--- libview/ev-jobs.c.orig	2019-02-20 16:30:35 UTC
+++ libview/ev-jobs.c
@@ -859,8 +859,6 @@ snapshot_callback(WebKitWebView *webview,
 	gtk_widget_destroy (gtk_widget_get_toplevel (webview));
 }
 
-#endif  /* ENABLE_EPUB */
-
 static void
 web_thumbnail_get_screenshot_cb (WebKitWebView  *webview,
                                  WebKitLoadEvent event,
@@ -893,6 +891,8 @@ webview_load_failed_cb (WebKitWebView  *webview,
 	
 	return TRUE;
 }
+
+#endif  /* ENABLE_EPUB */
 
 static gboolean
 ev_job_thumbnail_run (EvJob *job)
