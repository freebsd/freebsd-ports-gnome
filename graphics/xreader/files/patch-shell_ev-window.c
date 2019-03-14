--- shell/ev-window.c.orig	2019-02-20 16:30:35 UTC
+++ shell/ev-window.c
@@ -4657,13 +4657,6 @@ ev_window_cmd_view_autoscroll (GtkAction *action,
 
 #define EV_HELP "help:xreader"
 
-static void
-ev_window_cmd_help_contents (GtkAction *action,
-                             EvWindow *ev_window)
-{
-	ev_window_show_help(ev_window, NULL);
-}
-
 void
 ev_window_show_help (EvWindow *ev_window,
                      const gchar *uri)
@@ -4679,6 +4672,13 @@ ev_window_show_help (EvWindow *ev_window,
         ev_window_error_message(ev_window, error, "%s", _("There was an error displaying help"));
         g_error_free (error);
     }
+}
+
+static void
+ev_window_cmd_help_contents (GtkAction *action,
+                             EvWindow *ev_window)
+{
+	ev_window_show_help(ev_window, NULL);
 }
 
 static void
