Dirty hack to dodge hostnamed and grab the hostname via sysctl.

--- panels/common/cc-hostname-entry.c.orig	2019-03-11 19:06:23 UTC
+++ panels/common/cc-hostname-entry.c
@@ -189,6 +189,7 @@ cc_hostname_entry_constructed (GObject *object)
                                            NULL, NULL, NULL);
 
   /* Is hostnamed installed? */
+/*
   if (permission == NULL)
     {
       g_debug ("Will not show hostname, hostnamed not installed");
@@ -202,13 +203,14 @@ cc_hostname_entry_constructed (GObject *object)
     gtk_widget_set_sensitive (GTK_WIDGET (self), TRUE);
   else
     {
+*/
       g_debug ("Not allowed to change the hostname");
       gtk_widget_set_sensitive (GTK_WIDGET (self), FALSE);
-    }
+//    }
 
-  gtk_widget_set_sensitive (GTK_WIDGET (self),
-                            g_permission_get_allowed (permission));
-
+//  gtk_widget_set_sensitive (GTK_WIDGET (self),
+//                            g_permission_get_allowed (permission));
+/*
   self->hostnamed_proxy = g_dbus_proxy_new_for_bus_sync (G_BUS_TYPE_SYSTEM,
                                                          G_DBUS_PROXY_FLAGS_NONE,
                                                          NULL,
@@ -217,16 +219,29 @@ cc_hostname_entry_constructed (GObject *object)
                                                          "org.freedesktop.hostname1",
                                                          NULL,
                                                          &error);
-
+*/
   /* This could only happen if the policy file was installed
    * but not hostnamed, which points to a system bug */
-  if (self->hostnamed_proxy == NULL)
+/*  if (self->hostnamed_proxy == NULL)
     {
       g_debug ("Couldn't get hostnamed to start, bailing: %s", error->message);
       return;
     }
 
   str = cc_hostname_entry_get_display_hostname (CC_HOSTNAME_ENTRY (self));
+*/
+
+// This is not correct but will have to do for now.
+size_t value_len;
+
+  if (sysctlbyname("kern.hostname", NULL, &value_len, NULL, 0) == 0)
+    {
+      str = g_new(char, value_len + 1);
+      if (sysctlbyname("kern.hostname", str, &value_len, NULL, 0) == 0)
+        {
+          str = g_strndup(str, strlen(str));
+        }
+    }
 
   if (str != NULL)
     gtk_entry_set_text (GTK_ENTRY (self), str);
