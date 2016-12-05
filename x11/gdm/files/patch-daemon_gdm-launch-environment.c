--- daemon/gdm-launch-environment.c.orig	2015-08-16 16:56:01 UTC
+++ daemon/gdm-launch-environment.c
@@ -176,6 +176,9 @@ build_launch_environment (GdmLaunchEnvir
                 char *seat_id;
 
                 seat_id = launch_environment->priv->x11_display_seat_id;
+                if (g_str_has_prefix (seat_id, "/org/freedesktop/ConsoleKit/")) {
+                        seat_id += strlen ("/org/freedesktop/ConsoleKit/");
+                }
 
                 g_hash_table_insert (hash, g_strdup ("GDM_SEAT_ID"), g_strdup (seat_id));
         }
@@ -204,6 +207,8 @@ on_session_setup_complete (GdmSession   
                 gdm_session_set_environment_variable (launch_environment->priv->session, key, value);
         }
         g_hash_table_destroy (hash);
+
+        gdm_session_select_session_type (launch_environment->priv->session, "LoginWindow");
 }
 
 static void
