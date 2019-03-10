$OpenBSD: patch-daemon_gdm-server_c,v 1.10 2017/11/05 02:17:07 ajacoutot Exp $

REVERT - OpenBSD lacks sigwaitinfo(2)
From 956d7d1c7a0cfbf2beacdb9e88e645e15ad32047 Mon Sep 17 00:00:00 2001
From: Jasper St. Pierre <jstpierre@mecheye.net>
Date: Fri, 14 Feb 2014 19:32:50 +0000
Subject: server: Process SIGUSR1 more carefully

REVERT - OpenBSD does not have a systemd implementation (we need ConsoleKit)
From 1ac67f522f5690c27023d98096ca817f12f7eb88 Mon Sep 17 00:00:00 2001
From: Ray Strode <rstrode@redhat.com>
Date: Fri, 12 Jun 2015 13:28:01 -0400
Subject: drop consolekit support

REVERT - OpenBSD does not have a systemd implementation (we need ConsoleKit)
From 9be58c9ec9a3a411492a5182ac4b0d51fdc3a323 Mon Sep 17 00:00:00 2001
From: Ray Strode <rstrode@redhat.com>
Date: Fri, 12 Jun 2015 13:48:52 -0400
Subject: require logind support

--- daemon/gdm-server.c.orig	2019-02-21 19:44:14 UTC
+++ daemon/gdm-server.c
@@ -43,7 +43,9 @@
 #include <linux/vt.h>
 #endif
 
+#ifdef WITH_SYSTEMD
 #include <systemd/sd-daemon.h>
+#endif
 
 #ifdef ENABLE_SYSTEMD_JOURNAL
 #include <systemd/sd-journal.h>
@@ -114,11 +116,58 @@ static void     gdm_server_finalize     (GObject      
 
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
+                                   server->display_name);
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
+        if (server->display_device == NULL) {
+                server->display_device =
+                        _gdm_server_query_ck_for_display_device (server);
+                g_object_notify (G_OBJECT (server), "display-device");
+        }
+
+        return g_strdup (server->display_device);
 }
 
 static void
@@ -218,8 +267,10 @@ gdm_server_init_command (GdmServer *server)
                 debug_options = "";
         }
 
-#define X_SERVER_ARG_FORMAT " -background none -noreset -verbose %s%s"
+        #define X_SERVER_ARG_FORMAT " -background none -noreset -verbose %s%s"
 
+#ifdef WITH_SYSTEMD
+
         /* This is a temporary hack to work around the fact that XOrg
          * currently lacks support for multi-seat hotplugging for
          * display devices. This bit should be removed as soon as XOrg
@@ -234,6 +285,10 @@ gdm_server_init_command (GdmServer *server)
          * wasn't booted using systemd, or b) the wrapper tool is
          * missing, or c) we are running for the main seat 'seat0'. */
 
+        if (!LOGIND_RUNNING()) {
+                goto fallback;
+        }
+
 #ifdef ENABLE_SYSTEMD_JOURNAL
         /* For systemd, we don't have a log file but instead log to stdout,
            so set it to the xserver's built-in default verbosity */
@@ -256,6 +311,7 @@ gdm_server_init_command (GdmServer *server)
         return;
 
 fallback:
+#endif
         server->command = g_strdup_printf (X_SERVER X_SERVER_ARG_FORMAT, verbosity, debug_options);
 
 }
@@ -307,10 +363,12 @@ gdm_server_resolve_command_line (GdmServer  *server,
                 argv[len++] = g_strdup (server->auth_file);
         }
 
-        if (server->display_seat_id != NULL) {
+#ifdef WITH_SYSTEMD
+        if (LOGIND_RUNNING() && server->display_seat_id != NULL) {
                 argv[len++] = g_strdup ("-seat");
                 argv[len++] = g_strdup (server->display_seat_id);
         }
+#endif
 
         /* If we were compiled with Xserver >= 1.17 we need to specify
          * '-listen tcp' as the X server dosen't listen on tcp sockets
