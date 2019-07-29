$OpenBSD: patch-daemon_gdm-display_c,v 1.7 2019/05/08 21:32:35 ajacoutot Exp $

XXX fix+push upstream

Index: daemon/gdm-display.c
--- daemon/gdm-display.c.orig
+++ daemon/gdm-display.c
@@ -1720,7 +1720,6 @@ void
 gdm_display_stop_greeter_session (GdmDisplay *self)
 {
         GdmDisplayPrivate *priv;
-        GError *error = NULL;
 
         priv = gdm_display_get_instance_private (self);
 
