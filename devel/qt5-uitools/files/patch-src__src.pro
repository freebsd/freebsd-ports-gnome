Only enter the directories we want to build, otherwise we might fail due to
missing dependencies.

--- src/src.pro.orig	2018-09-21 17:46:35 UTC
+++ src/src.pro
@@ -1,48 +1,3 @@
 TEMPLATE = subdirs
 
-qtHaveModule(widgets) {
-    no-png {
-        message("Some graphics-related tools are unavailable without PNG support")
-    } else {
-        SUBDIRS = assistant \
-                  pixeltool \
-                  designer
-
-        linguist.depends = designer
-    }
-}
-
-SUBDIRS += linguist \
-    qtattributionsscanner
-
-qtConfig(library) {
-    !android|android_app: SUBDIRS += qtplugininfo
-}
-
-config_clang: SUBDIRS += qdoc
-
-if(!android|android_app):!uikit: SUBDIRS += qtpaths
-
-mac {
-    SUBDIRS += macdeployqt
-}
-
-qtHaveModule(dbus): SUBDIRS += qdbus
-
-win32|winrt:SUBDIRS += windeployqt
-winrt:SUBDIRS += winrtrunner
-qtHaveModule(gui):!android:!uikit:!qnx:!winrt: SUBDIRS += qtdiag
-
-qtNomakeTools( \
-    pixeltool \
-    macdeployqt \
-)
-
-# This is necessary to avoid a race condition between toolchain.prf
-# invocations in a module-by-module cross-build.
-cross_compile:isEmpty(QMAKE_HOST_CXX.INCDIRS) {
-    qdoc.depends += qtattributionsscanner
-    windeployqt.depends += qtattributionsscanner
-    winrtrunner.depends += qtattributionsscanner
-    linguist.depends += qtattributionsscanner
-}
+SUBDIRS = designer
