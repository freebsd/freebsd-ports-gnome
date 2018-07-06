--- src/af/gr/gtk/gr_UnixCairoGraphics.cpp.orig	2016-10-21 00:39:16 UTC
+++ src/af/gr/gtk/gr_UnixCairoGraphics.cpp
@@ -180,7 +180,7 @@ void GR_UnixCairoGraphics::init3dColors(GtkWidget* /*w
 	if (m_styleBg) {
 		g_object_unref(m_styleBg);
 	}
-	m_styleBg = XAP_GtkStyle_get_style(nullptr, "GtkButton"); // "button"
+	m_styleBg = XAP_GtkStyle_get_style(NULL, "GtkButton"); // "button"
 	// guess colours
 	// WHITE
 	GdkRGBA rgba2;
@@ -627,7 +627,7 @@ void GR_UnixCairoGraphics::fillRect(GR_Color3D c, UT_s
 		_setProps();
 		cairo_save (m_cr);
 
-		GtkStyleContext *context = nullptr;
+		GtkStyleContext *context = NULL;
 		switch(c) {
 		case GR_Graphics::CLR3D_Background:
 			context = m_styleBg;
