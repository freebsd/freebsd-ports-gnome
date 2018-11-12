This patch is necessary for us to split PyQt5 up into several different ports.

It works by conditionally building and installing some tools (such as
pylupdate5 and pyrcc5), replacing the all-encompassing PyQt5.api file that
depends on different modules with module-specific .api files.

Also fixes a bug where dbus support drops multiple -I flags produced
by pkg-config --cflags dbus-1 .

Also fixes the build of www/py-qt5-webengine@py36 by adding printsupport to
QtWebEngineWidgets.

Also causes .pyi files to be installed regardless of the Python version to
simplify plist handling.
--- configure.py.orig	2017-11-23 14:44:03 UTC
+++ configure.py
@@ -98,7 +98,7 @@ MODULE_METADATA = {
     'QtWebEngineCore':      ModuleMetadata(qmake_QT=['webenginecore', '-gui']),
     'QtWebEngineWidgets':   ModuleMetadata(
                                     qmake_QT=['webenginewidgets', 'webchannel',
-                                            'network', 'widgets'],
+                                              'network', 'printsupport', 'widgets'],
                                     cpp11=True),
     'QtWebKit':             ModuleMetadata(qmake_QT=['webkit', 'network']),
     'QtWebKitWidgets':      ModuleMetadata(
@@ -503,7 +503,7 @@ class TargetConfiguration:
         self.no_pydbus = False
         self.no_qml_plugin = False
         self.no_tools = False
-        self.prot_is_public = (self.py_platform.startswith('linux') or self.py_platform == 'darwin')
+        self.prot_is_public = (self.py_platform.startswith('linux') or self.py_platform.startswith('freebsd') or self.py_platform == 'darwin')
         self.qmake = self._find_exe('qmake')
         self.qmake_spec = ''
         self.qmake_spec_default = ''
@@ -773,7 +773,7 @@ class TargetConfiguration:
         """
 
         # The platform may have changed so update the default.
-        if self.py_platform.startswith('linux') or self.py_platform == 'darwin':
+        if self.py_platform.startswith('linux') or self.py_platform.startswith('freebsd') or self.py_platform == 'darwin':
             self.prot_is_public = True
 
         self.vend_inc_dir = self.py_venv_inc_dir
@@ -1450,8 +1450,9 @@ def generate_makefiles(target_config, verbose, parts, 
 
     # Add the internal modules if they are required.
     if not target_config.no_tools:
-        pyqt_modules.append('pylupdate')
-        pyqt_modules.append('pyrcc')
+        if "QtXml" in target_config.pyqt_modules:
+            pyqt_modules.append('pylupdate')
+            pyqt_modules.append('pyrcc')
 
     for mname in pyqt_modules:
         metadata = MODULE_METADATA[mname]
@@ -1493,20 +1494,17 @@ def generate_makefiles(target_config, verbose, parts, 
 
     f.close()
 
-    generate_sip_module_code(target_config, verbose, parts, tracing, 'Qt',
-            fatal_warnings, sip_flags, False)
-    subdirs.append('Qt')
-
     wrappers = []
     if not target_config.no_tools:
-        # Generate the pylupdate5 and pyrcc5 wrappers.
-        for tool in ('pylupdate', 'pyrcc'):
-            wrappers.append((tool,
-                    generate_tool_wrapper(target_config, tool + '5',
-                            'PyQt5.%s_main' % tool)))
-
-        # Generate the pyuic5 wrapper.
-        wrappers.append(('pyuic',
+        if "QtXml" in target_config.pyqt_modules:
+            # Generate the pylupdate5 and pyrcc5 wrappers.
+            for tool in ('pylupdate', 'pyrcc'):
+                wrappers.append((tool,
+                        generate_tool_wrapper(target_config, tool + '5',
+                                'PyQt5.%s_main' % tool)))
+        if "QtCore" in target_config.pyqt_modules:
+            # Generate the pyuic5 wrapper.
+            wrappers.append(('pyuic',
                 generate_tool_wrapper(target_config, 'pyuic5',
                         'PyQt5.uic.pyuic')))
 
@@ -1524,23 +1522,6 @@ def generate_makefiles(target_config, verbose, parts, 
                     source_path('examples', 'quick', 'tutorials', 'extending',
                             'chapter6-plugins'))
 
-    # Generate the QScintilla API file.
-    if target_config.qsci_api:
-        inform("Generating the QScintilla API file...")
-        f = open_for_writing('PyQt5.api')
-
-        for mname in target_config.pyqt_modules:
-            if MODULE_METADATA[mname].public:
-                api = open(mname + '.api')
-
-                for l in api:
-                    f.write('PyQt5.' + l)
-
-                api.close()
-                os.remove(mname + '.api')
-
-        f.close()
-
     # Generate the Python dbus module.
     if target_config.pydbus_module_dir != '':
         mname = 'dbus'
@@ -1568,14 +1549,18 @@ def generate_makefiles(target_config, verbose, parts, 
     out_f.write('''TEMPLATE = subdirs
 CONFIG += ordered nostrip
 SUBDIRS = %s
+''' % (' '.join(subdirs)))
 
+    if "QtCore" in target_config.pyqt_modules:
+        out_f.write('''
 init_py.files = %s
 init_py.path = %s
 INSTALLS += init_py
-''' % (' '.join(subdirs), source_path('__init__.py'), root_dir))
+''' % (source_path('__init__.py'), root_dir))
 
-    # Install the uic module.
-    out_f.write('''
+        if not target_config.no_tools:
+            # Install the uic module.
+            out_f.write('''
 uic_package.files = %s
 uic_package.path = %s
 INSTALLS += uic_package
@@ -1603,6 +1588,8 @@ INSTALLS += tools
     # Install the .sip files.
     if target_config.pyqt_sip_dir:
         for mname, metadata in MODULE_METADATA.items():
+            if mname not in pyqt_modules:
+                continue
             if metadata.public and mname != 'Qt':
                 sip_files = matching_files(source_path('sip', mname, '*.sip'))
 
@@ -1618,7 +1605,7 @@ INSTALLS += sip%s
 ))
 
     # Install the stub files.
-    if target_config.py_version >= 0x030500 and target_config.pyqt_stubs_dir:
+    if target_config.pyqt_stubs_dir:
         out_f.write('''
 pep484_stubs.files = %s Qt.pyi
 pep484_stubs.path = %s
@@ -1628,11 +1615,12 @@ INSTALLS += pep484_stubs
 
     # Install the QScintilla .api file.
     if target_config.qsci_api:
+        api_list = ' '.join(['%s.api' % m for m in target_config.pyqt_modules])
         out_f.write('''
-qscintilla_api.files = PyQt5.api
+qscintilla_api.files = %s
 qscintilla_api.path = %s
 INSTALLS += qscintilla_api
-''' % qmake_quote(target_config.qsci_api_dir + '/api/python'))
+''' % (api_list, qmake_quote(target_config.qsci_api_dir + '/api/python')))
 
     out_f.close()
 
@@ -1864,7 +1852,7 @@ def inform_user(target_config, sip_version):
                         os.path.join(
                                 target_config.qsci_api_dir, 'api', 'python'))
 
-    if target_config.py_version >= 0x030500 and target_config.pyqt_stubs_dir:
+    if target_config.pyqt_stubs_dir:
         inform("The PyQt5 PEP 484 stub files will be installed in %s." %
                 target_config.pyqt_stubs_dir)
 
@@ -2431,7 +2419,7 @@ def generate_sip_module_code(target_config, verbose, p
             argv.append('-a')
             argv.append(mname + '.api')
 
-        if target_config.py_version >= 0x030500 and target_config.pyqt_stubs_dir:
+        if target_config.pyqt_stubs_dir:
             argv.append('-y')
             argv.append(mname + '.pyi')
 
@@ -2604,7 +2592,7 @@ target.files = $$PY_MODULE
     pro_lines.append('INSTALLS += target')
 
     # This optimisation could apply to other platforms.
-    if 'linux' in target_config.qmake_spec and not target_config.static:
+    if not target_config.static:
         if target_config.py_version >= 0x030000:
             entry_point = 'PyInit_%s' % target_name
         else:
