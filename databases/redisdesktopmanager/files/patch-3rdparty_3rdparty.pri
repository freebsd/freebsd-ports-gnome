--- 3rdparty/3rdparty.pri.orig	2018-09-22 00:19:48 UTC
+++ 3rdparty/3rdparty.pri
@@ -81,15 +81,11 @@ unix:!macx { # ubuntu & debian
         #QMAKE_LFLAGS = -Wl,-rpath=/home/user/Qt5.9.3/5.9.3/gcc_64/lib
     }
 
-    LIBS += $$BREAKPADDIR/client/linux/libbreakpad_client.a
-
     # Unix signal watcher
-    defined(LINUX_SIGNALS, var) {
-        DEFINES += LINUX_SIGNALS
+    DEFINES += LINUX_SIGNALS
 
-        HEADERS += $$PWD/qt-unix-signals/sigwatch.h
-        HEADERS += $$PWD/qt-unix-signals/sigwatch_p.h
-        SOURCES += $$PWD/qt-unix-signals/sigwatch.cpp
-        INCLUDEPATH += $$PWD/qt-unix-signals/
-    }
+    HEADERS += $$PWD/qt-unix-signals/sigwatch.h
+    HEADERS += $$PWD/qt-unix-signals/sigwatch_p.h
+    SOURCES += $$PWD/qt-unix-signals/sigwatch.cpp
+    INCLUDEPATH += $$PWD/qt-unix-signals/
 }
