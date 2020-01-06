--- src/contacts-window.vala.orig	2020-01-06 21:35:38 UTC
+++ src/contacts-window.vala
@@ -35,9 +35,9 @@ public class Contacts.Window : Gtk.ApplicationWindow {
   [GtkChild]
   private TitleBar titlebar;
   [GtkChild]
-  private HeaderBar left_header;
+  private Gtk.HeaderBar left_header;
   [GtkChild]
-  private HeaderBar right_header;
+  private Gtk.HeaderBar right_header;
   [GtkChild]
   private Overlay notification_overlay;
   [GtkChild]
