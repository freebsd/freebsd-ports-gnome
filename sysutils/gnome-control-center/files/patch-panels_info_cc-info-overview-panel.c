Add code to grap OS name on FreebSD via sysctl.

and

REVERT

From 2520aea647c8e0ce39b750b0758db8b770eafdcb Mon Sep 17 00:00:00 2001
From: Georges Basile Stavracas Neto <georges.stavracas@gmail.com>
Date: Thu, 23 Nov 2017 10:15:29 -0200
Subject: [PATCH] info: use UDisks to retrieve disk size

The current code relies on GLib API and uses the
available mounts to calculate the available partition
size. This is because this code assumes that more
than one OS can be installed in the same drive, and
wouldn't make sense to show the whole disk size in
this situation.

That, however, clashes with the general purpose of
the panel, for it is meant to show general information
about the user's computer, and it is not reporting
the full disk size.

Fix that by using the UDisks API to get the real size
of the full disks.

https://bugzilla.gnome.org/show_bug.cgi?id=639376

Slighly modified by Iain Lane <iainl@gnome.org> to
port to meson and add udisks2 to CI deps.

Fixes #285.
Fixes #302.

--- panels/info/cc-info-overview-panel.c.orig	2019-03-11 19:06:23 UTC
+++ panels/info/cc-info-overview-panel.c
@@ -32,11 +32,15 @@
 #include <gio/gunixmounts.h>
 #include <gio/gdesktopappinfo.h>
 
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
+
 #include <glibtop/fsusage.h>
 #include <glibtop/mountlist.h>
 #include <glibtop/mem.h>
 #include <glibtop/sysinfo.h>
-#include <udisks/udisks.h>
 
 #include <gdk/gdk.h>
 
@@ -82,7 +86,9 @@ typedef struct
 
   GCancellable   *cancellable;
 
-  UDisksClient   *client;
+  /* Free space */
+  GList          *primary_mounts;
+  guint64         total_bytes;
 
   GraphicsData   *graphics_data;
 } CcInfoOverviewPanelPrivate;
@@ -95,6 +101,8 @@ struct _CcInfoOverviewPanel
  CcInfoOverviewPanelPrivate *priv;
 };
 
+static void get_primary_disc_info_start (CcInfoOverviewPanel *self);
+
 typedef struct
 {
   char *major;
@@ -425,6 +433,26 @@ get_os_info (void)
         }
     }
 
+#if defined(__FreeBSD__)
+  size_t value_len;
+  gchar *str = NULL, *value;
+
+  /* Initialize the hash table if needed */
+  if (!hashtable)
+    hashtable = g_hash_table_new_full (g_str_hash, g_str_equal, g_free, g_free);
+
+  if (sysctlbyname("kern.version", NULL, &value_len, NULL, 0) == 0)
+    {
+      str = g_new(char, value_len + 1);
+      if (sysctlbyname("kern.version", str, &value_len, NULL, 0) == 0)
+        {
+          // get rid of those pesky new lines
+          value = g_strndup(str, strlen(str) - 1);
+          g_hash_table_insert (hashtable, "PRETTY_NAME", value);
+        }
+    }
+#endif
+
   return hashtable;
 }
 
@@ -466,7 +494,8 @@ get_os_name (void)
       result = g_strdup (name_version);
     }
 
-  g_clear_pointer (&os_info, g_hash_table_destroy);
+// XXX This is a memory leak but is currently segfaulting, need to readup on hashtable magic...
+//  g_clear_pointer (&os_info, g_hash_table_destroy);
 
   return result;
 }
@@ -483,51 +512,111 @@ get_os_type (void)
 }
 
 static void
-get_primary_disc_info (CcInfoOverviewPanel *self)
+query_done (GFile               *file,
+            GAsyncResult        *res,
+            CcInfoOverviewPanel *self)
 {
   CcInfoOverviewPanelPrivate *priv;
-  GDBusObjectManager *manager;
-  g_autolist(GDBusObject) objects = NULL;
-  GList *l;
-  guint64 total_size;
+  g_autoptr(GFileInfo) info = NULL;
+  g_autoptr(GError) error = NULL;
 
-  priv = cc_info_overview_panel_get_instance_private (self);
-  total_size = 0;
+  info = g_file_query_filesystem_info_finish (file, res, &error);
+  if (info != NULL)
+    {
+      priv = cc_info_overview_panel_get_instance_private (self);
+      priv->total_bytes += g_file_info_get_attribute_uint64 (info, G_FILE_ATTRIBUTE_FILESYSTEM_SIZE);
+    }
+  else
+    {
+      if (g_error_matches (error, G_IO_ERROR, G_IO_ERROR_CANCELLED))
+          return;
+      else
+        {
+          g_autofree char *path = NULL;
+          path = g_file_get_path (file);
+          g_warning ("Failed to get filesystem free space for '%s': %s", path, error->message);
+        }
+    }
 
-  if (!priv->client)
+  /* And onto the next element */
+  get_primary_disc_info_start (self);
+}
+
+static void
+get_primary_disc_info_start (CcInfoOverviewPanel *self)
+{
+  GUnixMountEntry *mount;
+  g_autoptr(GFile) file = NULL;
+  CcInfoOverviewPanelPrivate *priv = cc_info_overview_panel_get_instance_private (self);
+
+  if (priv->primary_mounts == NULL)
     {
-      gtk_label_set_text (GTK_LABEL (priv->disk_label), _("Unknown"));
+      g_autofree char *size = NULL;
+
+      size = g_format_size (priv->total_bytes);
+      gtk_label_set_text (GTK_LABEL (priv->disk_label), size);
+
       return;
     }
 
-  manager = udisks_client_get_object_manager (priv->client);
-  objects = g_dbus_object_manager_get_objects (manager);
+  mount = priv->primary_mounts->data;
+  priv->primary_mounts = g_list_remove (priv->primary_mounts, mount);
+  file = g_file_new_for_path (g_unix_mount_get_mount_path (mount));
+  g_unix_mount_free (mount);
 
-  for (l = objects; l != NULL; l = l->next)
+  g_file_query_filesystem_info_async (file,
+                                      G_FILE_ATTRIBUTE_FILESYSTEM_SIZE,
+                                      0,
+                                      priv->cancellable,
+                                      (GAsyncReadyCallback) query_done,
+                                      self);
+}
+
+static void
+get_primary_disc_info (CcInfoOverviewPanel *self)
+{
+  GList *points;
+  GList *p;
+  GHashTable *hash;
+  CcInfoOverviewPanelPrivate *priv = cc_info_overview_panel_get_instance_private (self);
+
+  hash = g_hash_table_new (g_str_hash, g_str_equal);
+  points = g_unix_mount_points_get (NULL);
+
+  /* If we do not have /etc/fstab around, try /etc/mtab */
+  if (points == NULL)
+    points = g_unix_mounts_get (NULL);
+
+  for (p = points; p != NULL; p = p->next)
     {
-      UDisksDrive *drive;
-      drive = udisks_object_peek_drive (UDISKS_OBJECT (l->data));
+      GUnixMountEntry *mount = p->data;
+      const char *mount_path;
+      const char *device_path;
 
-      /* Skip removable devices */
-      if (drive == NULL ||
-          udisks_drive_get_removable (drive) ||
-          udisks_drive_get_ejectable (drive))
+      mount_path = g_unix_mount_get_mount_path (mount);
+      device_path = g_unix_mount_get_device_path (mount);
+
+      /* Do not count multiple mounts with same device_path, because it is
+       * probably something like btrfs subvolume. Use only the first one in
+       * order to count the real size. */
+      if (gsd_should_ignore_unix_mount (mount) ||
+          gsd_is_removable_mount (mount) ||
+          g_str_has_prefix (mount_path, "/media/") ||
+          g_str_has_prefix (mount_path, g_get_home_dir ()) ||
+          g_hash_table_lookup (hash, device_path) != NULL)
         {
+          g_unix_mount_free (mount);
           continue;
         }
 
-      total_size += udisks_drive_get_size (drive);
+      priv->primary_mounts = g_list_prepend (priv->primary_mounts, mount);
+      g_hash_table_insert (hash, (gpointer) device_path, (gpointer) device_path);
     }
+  g_list_free (points);
+  g_hash_table_destroy (hash);
 
-  if (total_size > 0)
-    {
-      g_autofree gchar *size = g_format_size (total_size);
-      gtk_label_set_text (GTK_LABEL (priv->disk_label), size);
-    }
-  else
-    {
-      gtk_label_set_text (GTK_LABEL (priv->disk_label), _("Unknown"));
-    }
+  priv->cancellable = g_cancellable_new ();
+  get_primary_disc_info_start (self);
 }
 
 static char *
@@ -789,7 +878,8 @@ cc_info_overview_panel_finalize (GObject *object)
       g_clear_object (&priv->cancellable);
     }
 
-  g_clear_object (&priv->client);
+  if (priv->primary_mounts)
+    g_list_free_full (priv->primary_mounts, (GDestroyNotify) g_unix_mount_free);
 
   g_free (priv->gnome_version);
   g_free (priv->gnome_date);
@@ -831,7 +921,6 @@ static void
 cc_info_overview_panel_init (CcInfoOverviewPanel *self)
 {
   CcInfoOverviewPanelPrivate *priv = cc_info_overview_panel_get_instance_private (self);
-  g_autoptr(GError) error = NULL;
 
   gtk_widget_init_template (GTK_WIDGET (self));
 
@@ -843,12 +932,6 @@ cc_info_overview_panel_init (CcInfoOverviewPanel *self
     g_signal_connect (priv->updates_button, "clicked", G_CALLBACK (on_updates_button_clicked), self);
   else
     gtk_widget_destroy (priv->updates_button);
-
-  priv->client = udisks_client_new_sync (NULL, &error);
-
-  if (error != NULL)
-      g_warning ("Unable to get UDisks client: %s. Disk information will not be available.",
-                 error->message);
 
   info_overview_panel_setup_overview (self);
   info_overview_panel_setup_virt (self);
