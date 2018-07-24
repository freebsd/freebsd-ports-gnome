--- src/af/xap/gtk/xap_UnixFrameImpl.cpp.orig	2014-12-14 14:56:47 UTC
+++ src/af/xap/gtk/xap_UnixFrameImpl.cpp
@@ -1208,9 +1208,9 @@ gint XAP_UnixFrameImpl::_fe::delete_event(GtkWidget * 
 }
 
 #if GTK_CHECK_VERSION(3,0,0)
-gint XAP_UnixFrameImpl::_fe::draw(GtkWidget * w, cairo_t * cr)
+gboolean XAP_UnixFrameImpl::_fe::draw(GtkWidget * w, cairo_t * cr)
 #else
-gint XAP_UnixFrameImpl::_fe::expose(GtkWidget * w, GdkEventExpose* pExposeEvent)
+gboolean XAP_UnixFrameImpl::_fe::expose(GtkWidget * w, GdkEventExpose* pExposeEvent)
 #endif
 {
 	XAP_UnixFrameImpl * pUnixFrameImpl = static_cast<XAP_UnixFrameImpl *>(g_object_get_data(G_OBJECT(w), "user_data"));
@@ -1243,7 +1243,7 @@ gint XAP_UnixFrameImpl::_fe::expose(GtkWidget * w, Gdk
 		pView->draw(&rClip);
 #endif
 	}
-	return FALSE;
+	return TRUE;
 }
 
 static bool bScrollWait = false;
