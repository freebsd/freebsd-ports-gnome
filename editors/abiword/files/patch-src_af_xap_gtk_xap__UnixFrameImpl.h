--- src/af/xap/gtk/xap_UnixFrameImpl.h.orig	2013-04-07 13:53:03 UTC
+++ src/af/xap/gtk/xap_UnixFrameImpl.h
@@ -152,9 +152,9 @@ class XAP_UnixFrameImpl : public XAP_FrameImpl (protec
 			static gint key_release_event(GtkWidget* w, GdkEventKey* e);
 			static gint delete_event(GtkWidget * w, GdkEvent * /*event*/, gpointer /*data*/);
 #if GTK_CHECK_VERSION(3,0,0)
-			static gint draw(GtkWidget * w, cairo_t * cr);
+			static gboolean draw(GtkWidget * w, cairo_t * cr);
 #else
-			static gint expose(GtkWidget * w, GdkEventExpose* pExposeEvent);
+			static gboolean expose(GtkWidget * w, GdkEventExpose* pExposeEvent);
 #endif
 			static gint do_ZoomUpdate( gpointer /* xap_UnixFrame * */ p);
 			static void vScrollChanged(GtkAdjustment * w, gpointer /*data*/);
