--- gdk/broadway/gdkscreen-broadway.h.orig	2016-12-13 14:13:11.450387000 +0100
+++ gdk/broadway/gdkscreen-broadway.h	2016-12-13 14:13:16.681614000 +0100
@@ -38,7 +38,6 @@
 #define GDK_IS_BROADWAY_SCREEN_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), GDK_TYPE_BROADWAY_SCREEN))
 #define GDK_BROADWAY_SCREEN_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), GDK_TYPE_BROADWAY_SCREEN, GdkBroadwayScreenClass))
 
-typedef struct _GdkBroadwayMonitor GdkBroadwayMonitor;
 
 struct _GdkBroadwayScreen
 {
