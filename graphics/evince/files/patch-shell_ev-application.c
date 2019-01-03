--- shell/ev-application.c.orig	2019-01-03 23:04:13 UTC
+++ shell/ev-application.c
@@ -64,8 +64,8 @@ struct _EvApplicationClass {
 
 G_DEFINE_TYPE (EvApplication, ev_application, GTK_TYPE_APPLICATION)
 
-#ifdef ENABLE_DBUS
 #define APPLICATION_NAME             "org.gnome.Evince"
+#ifdef ENABLE_DBUS
 #define APPLICATION_DBUS_OBJECT_PATH "/org/gnome/evince/Evince"
 #define APPLICATION_DBUS_INTERFACE   "org.gnome.evince.Application"
 
