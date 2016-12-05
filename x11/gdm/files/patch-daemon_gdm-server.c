--- daemon/gdm-server.c.orig	2015-08-16 16:56:01 UTC
+++ daemon/gdm-server.c
@@ -43,7 +43,9 @@
 #include <linux/vt.h>
 #endif
 
+#ifdef WITH_SYSTEMD
 #include <systemd/sd-daemon.h>
+#endif
 
 #ifdef ENABLE_SYSTEMD_JOURNAL
 #include <systemd/sd-journal.h>
@@ -122,11 +124,59 @@ static void     gdm_server_finalize     
 
 G_DEFINE_TYPE (GdmServer, gdm_server, G_TYPE_OBJECT)
 
+static char *
+_gdm_server_query_ck_for_display_device (GdmServer *server)
+{
+        char    *out;
+        char    *command;
+        int      status;
+        gboolean res;
+        GError  *error;
+
+        g_return_val_if_fail (GDM_IS_SERVER (server), NULL);
+
+        error = NULL;
+        command = g_strdup_printf (CONSOLEKIT_DIR "/ck-get-x11-display-device --display %s",
+                                   server->priv->display_name);
+
+        g_debug ("GdmServer: Running helper %s", command);
+        out = NULL;
+        res = g_spawn_command_line_sync (command,
+                                         &out,
+                                         NULL,
+                                         &status,
+                                         &error);
+        if (! res) {
+                g_warning ("Could not run helper: %s", error->message);
+                g_error_free (error);
+        } else {
+                out = g_strstrip (out);
+                g_debug ("GdmServer: Got tty: '%s'", out);
+        }
+
+        g_free (command);
+
+        return out;
+}
+
 char *
 gdm_server_get_display_device (GdmServer *server)
 {
-        /* systemd finds the display device out on its own based on the display */
-        return NULL;
+#ifdef WITH_SYSTEMD
+        if (LOGIND_RUNNING()) {
+                /* systemd finds the display device out on its own based on the display */
+                return NULL;
+        }
+#endif
+
+        if (server->priv->display_device == NULL) {
+                server->priv->display_device =
+                    _gdm_server_query_ck_for_display_device (server);
+
+                g_object_notify (G_OBJECT (server), "display-device");
+        }
+
+        return g_strdup (server->priv->display_device);
 }
 
 static void
@@ -228,6 +278,8 @@ gdm_server_init_command (GdmServer *serv
 
 #define X_SERVER_ARG_FORMAT " -background none -noreset -verbose %s%s"
 
+#ifdef WITH_SYSTEMD
+
         /* This is a temporary hack to work around the fact that XOrg
          * currently lacks support for multi-seat hotplugging for
          * display devices. This bit should be removed as soon as XOrg
@@ -242,6 +294,10 @@ gdm_server_init_command (GdmServer *serv
          * wasn't booted using systemd, or b) the wrapper tool is
          * missing, or c) we are running for the main seat 'seat0'. */
 
+        if (!LOGIND_RUNNING()) {
+                goto fallback;
+        }
+
 #ifdef ENABLE_SYSTEMD_JOURNAL
         /* For systemd, we don't have a log file but instead log to stdout,
            so set it to the xserver's built-in default verbosity */
@@ -264,8 +320,9 @@ gdm_server_init_command (GdmServer *serv
         return;
 
 fallback:
-        server->priv->command = g_strdup_printf (X_SERVER X_SERVER_ARG_FORMAT, verbosity, debug_options);
+#endif
 
+        server->priv->command = g_strdup_printf (X_SERVER X_SERVER_ARG_FORMAT, verbosity, debug_options);
 }
 
 static gboolean
@@ -315,10 +372,12 @@ gdm_server_resolve_command_line (GdmServ
                 argv[len++] = g_strdup (server->priv->auth_file);
         }
 
-        if (server->priv->display_seat_id != NULL) {
+#ifdef WITH_SYSTEMD
+        if (LOGIND_RUNNING() && server->priv->display_seat_id != NULL) {
                 argv[len++] = g_strdup ("-seat");
                 argv[len++] = g_strdup (server->priv->display_seat_id);
         }
+#endif
 
         if (server->priv->disable_tcp && ! query_in_arglist) {
                 argv[len++] = g_strdup ("-nolisten");
