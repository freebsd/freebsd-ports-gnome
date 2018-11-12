--- setup.py.orig	2018-09-03 22:00:39 UTC
+++ setup.py
@@ -39,10 +39,6 @@ else:
         cf.add_section('install')
     except DuplicateSectionError:
         pass
-    if not cf.has_option('install', 'prefix'):
-        cf.set('install', 'prefix', '/opt/graphite')
-    if not cf.has_option('install', 'install-lib'):
-        cf.set('install', 'install-lib', '%(prefix)s/webapp')
 
 with open('setup.cfg', 'w') as f:
     cf.write(f)
@@ -58,17 +54,17 @@ else:
 
 storage_dirs = []
 
-for subdir in ('whisper/dummy.txt', 'ceres/dummy.txt', 'rrd/dummy.txt', 'log/dummy.txt', 'log/webapp/dummy.txt'):
-  storage_dirs.append( ('storage/%s' % subdir, []) )
+for subdir in ('whisper', 'ceres', 'rrd', 'log', 'log/webapp'):
+  storage_dirs.append( ('graphite/storage/%s' % subdir, []) )
 
 webapp_content = defaultdict(list)
 
-for root, dirs, files in os.walk('webapp/content'):
+for root, dirs, files in os.walk('graphite/webapp/content'):
   for filename in files:
     filepath = os.path.join(root, filename)
     webapp_content[root].append(filepath)
 
-conf_files = [ ('conf', glob('conf/*.example')) ]
+conf_files = [ ('%%PREFIX%%/etc/graphite', glob('conf/*.example')) ]
 examples = [ ('examples', glob('examples/example-*')) ]
 
 try:
@@ -108,7 +104,7 @@ try:
       package_data={'graphite' :
         ['templates/*', 'local_settings.py.example']},
       scripts=glob('bin/*'),
-      data_files=list(webapp_content.items()) + storage_dirs + conf_files + examples,
+      data_files=list(conf_files),
       install_requires=['Django>=1.8,<2.1', 'django-tagging==0.4.3', 'pytz', 'pyparsing', 'cairocffi', 'urllib3', 'scandir', 'six'],
       classifiers=[
           'Intended Audience :: Developers',
