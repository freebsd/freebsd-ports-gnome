--- common/gdm-log.c.orig	2015-07-20 13:13:40 UTC
+++ common/gdm-log.c
@@ -30,7 +30,9 @@
 #include <unistd.h>
 
 #include <syslog.h>
+#ifdef WITH_SYSTEMD
 #include <systemd/sd-daemon.h>
+#endif
 
 #include <glib.h>
 #include <glib/gstdio.h>
@@ -133,7 +135,27 @@ gdm_log_init (void)
 
         initialized = TRUE;
 
+#ifdef WITH_SYSTEMD
+        is_sd_booted = sd_booted () > 0;
+#endif
+
         g_log_set_default_handler (gdm_log_default_handler, NULL);
+
+        /* Only set up syslog if !systemd, otherwise with systemd
+         * enabled, we keep the default GLib log handler which goes to
+         * stderr, which is routed to the appropriate place in the
+         * systemd service file.
+         */
+        if (!is_sd_booted) {
+                prg_name = g_get_prgname ();
+
+                options = LOG_PID;
+#ifdef LOG_PERROR
+                options |= LOG_PERROR;
+#endif
+
+                openlog (prg_name, options, LOG_DAEMON);
+        }
 }
 
 void
