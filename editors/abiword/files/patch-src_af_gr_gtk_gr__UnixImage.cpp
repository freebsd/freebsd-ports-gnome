--- src/af/gr/gtk/gr_UnixImage.cpp.orig	2015-10-16 02:42:45 UTC
+++ src/af/gr/gtk/gr_UnixImage.cpp
@@ -244,12 +244,13 @@ bool GR_UnixImage::saveToPNG(const char * szFile)
         UT_return_val_if_fail(m_image,false);
 
 	GError * error = NULL;
-	gboolean res = gdk_pixbuf_save (m_image, szFile, "png", &error,NULL);
-	if(res != FALSE)
-	{
+	gboolean res = gdk_pixbuf_save (m_image, szFile, "png", &error, NULL);
+	if (res != FALSE) {
+		if (error) {
+			g_error_free (error);
+		}
 		return true;
 	}
-	delete error;
 	return false;
 
 }
