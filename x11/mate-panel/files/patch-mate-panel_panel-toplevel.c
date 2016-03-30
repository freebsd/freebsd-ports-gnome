--- mate-panel/panel-toplevel.c.orig	2016-03-30 14:35:55.711152000 +0200
+++ mate-panel/panel-toplevel.c	2016-03-30 14:36:11.012443000 +0200
@@ -3327,6 +3327,7 @@
 #endif
 
 #if GTK_CHECK_VERSION (3, 18, 0)
+static void
 set_background_region (PanelToplevel *toplevel)
 {
 	GtkWidget *widget;
