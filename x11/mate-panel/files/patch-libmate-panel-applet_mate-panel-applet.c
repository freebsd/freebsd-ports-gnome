Some how the window ends up being NULL in some cases. This breaks adding
applets. I wasn't able to find where this call comes from. 

While background might not work, at least it doesn't crash now.

-kwm

--- libmate-panel-applet/mate-panel-applet.c.orig	2015-11-30 08:37:55.000000000 +0100
+++ libmate-panel-applet/mate-panel-applet.c	2016-01-10 11:53:19.628092000 +0100
@@ -1788,6 +1788,11 @@
 	GdkWindow* window = gtk_widget_get_window(GTK_WIDGET(applet));
 	gtk_widget_set_app_paintable(GTK_WIDGET(applet),TRUE);
 	_mate_panel_applet_apply_css(GTK_WIDGET(applet->priv->plug),type);
+	if (window == NULL)
+	{
+	  g_warning("mate_panel_applet_change_background(), window is NULL. type: %i. Bailing\n", type);
+	  return;
+	}
 	switch (type) {
 	case PANEL_NO_BACKGROUND:
 		gdk_window_set_background_pattern(window,NULL);
