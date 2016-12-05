--- daemon/gdm-local-display-factory.c.orig	2016-02-24 19:10:08.000000000 +0100
+++ daemon/gdm-local-display-factory.c	2016-04-07 14:28:08.131406000 +0200
@@ -46,6 +46,8 @@
 #define GDM_LOCAL_DISPLAY_FACTORY_DBUS_PATH GDM_DBUS_PATH "/LocalDisplayFactory"
 #define GDM_MANAGER_DBUS_NAME               "org.gnome.DisplayManager.LocalDisplayFactory"
 
+#define CK_SEAT1_PATH                       "/org/freedesktop/ConsoleKit/Seat1"
+
 #define MAX_DISPLAY_FAILURES 5
 
 struct GdmLocalDisplayFactoryPrivate
@@ -206,7 +208,19 @@
 
         g_debug ("GdmLocalDisplayFactory: Creating transient display");
 
-        display = gdm_local_display_new ();
+#ifdef WITH_SYSTEMD
+        if (LOGIND_RUNNING() > 0) {
+                display = gdm_local_display_new ();
+        }
+#endif
+
+        if (display == NULL) {
+                guint32 num;
+
+                num = take_next_display_number (factory);
+
+                display = gdm_legacy_display_new (num);
+        }
 
         g_object_set (display,
                       "seat-id", "seat0"
@@ -279,7 +293,7 @@
                         /* reset num failures */
                         factory->priv->num_failures = 0;
 
-                        gdm_local_display_factory_sync_seats (factory);
+                        create_display (factory, seat_id, session_type, is_initial);
                 }
                 break;
         case GDM_DISPLAY_FAILED:
@@ -359,12 +373,14 @@
         g_debug ("GdmLocalDisplayFactory: Adding display on seat %s", seat_id);
 
 
+#ifdef WITH_SYSTEMD
         if (g_strcmp0 (seat_id, "seat0") == 0) {
                 display = gdm_local_display_new ();
                 if (session_type != NULL) {
                         g_object_set (G_OBJECT (display), "session-type", session_type, NULL);
                 }
         }
+#endif
 
         if (display == NULL) {
                 guint32 num;
@@ -389,6 +405,8 @@
         return display;
 }
 
+#ifdef WITH_SYSTEMD
+
 static void
 delete_display (GdmLocalDisplayFactory *factory,
                 const char             *seat_id) {
@@ -525,6 +543,7 @@
                 factory->priv->seat_removed_id = 0;
         }
 }
+#endif
 
 static void
 on_display_added (GdmDisplayStore        *display_store,
@@ -563,6 +582,7 @@
 gdm_local_display_factory_start (GdmDisplayFactory *base_factory)
 {
         GdmLocalDisplayFactory *factory = GDM_LOCAL_DISPLAY_FACTORY (base_factory);
+        GdmDisplay		*display;
         GdmDisplayStore *store;
 
         g_return_val_if_fail (GDM_IS_LOCAL_DISPLAY_FACTORY (factory), FALSE);
@@ -579,8 +599,17 @@
                           G_CALLBACK (on_display_removed),
                           factory);
 
-        gdm_local_display_factory_start_monitor (factory);
-        return gdm_local_display_factory_sync_seats (factory);
+#ifdef WITH_SYSTEMD
+	if (LOGIND_RUNNING()) {
+        	gdm_local_display_factory_start_monitor (factory);
+        	return gdm_local_display_factory_sync_seats (factory);
+	}
+#endif
+
+	/* On ConsoleKit just create Seat1, and that's it. */
+        display = create_display (factory, CK_SEAT1_PATH, NULL, TRUE);
+
+        return display != NULL;
 }
 
 static gboolean
@@ -591,7 +620,9 @@
 
         g_return_val_if_fail (GDM_IS_LOCAL_DISPLAY_FACTORY (factory), FALSE);
 
+#ifdef WITH_SYSTEMD
         gdm_local_display_factory_stop_monitor (factory);
+#endif
 
         store = gdm_display_factory_get_display_store (GDM_DISPLAY_FACTORY (factory));
 
@@ -601,7 +632,6 @@
         g_signal_handlers_disconnect_by_func (G_OBJECT (store),
                                               G_CALLBACK (on_display_removed),
                                               factory);
-
         return TRUE;
 }
 
@@ -747,7 +777,9 @@
 
         g_hash_table_destroy (factory->priv->used_display_numbers);
 
+#ifdef WITH_SYSTEMD
         gdm_local_display_factory_stop_monitor (factory);
+#endif
 
         G_OBJECT_CLASS (gdm_local_display_factory_parent_class)->finalize (object);
 }
