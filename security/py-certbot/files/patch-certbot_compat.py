# Incorrect config file path since update to 0.29.1
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=233909
# TODO: Upstream

--- certbot/compat.py.orig	2019-02-07 21:20:29 UTC
+++ certbot/compat.py
@@ -187,6 +187,11 @@ LINUX_DEFAULT_FOLDERS = {
     'work': '/var/lib/letsencrypt',
     'logs': '/var/log/letsencrypt',
 }
+FREEBSD_DEFAULT_FOLDERS = {
+    'config': '/usr/local/etc/letsencrypt',
+    'work': '/var/db/letsencrypt',
+    'logs': '/var/log/letsencrypt',
+}
 
 
 def get_default_folder(folder_type):
@@ -200,8 +205,13 @@ def get_default_folder(folder_type):
 
     """
     if os.name != 'nt':
-        # Linux specific
-        return LINUX_DEFAULT_FOLDERS[folder_type]
+        # Unix-like
+        if sys.platform.startswith('freebsd') or sys.platform.startswith('dragonfly'):
+            # FreeBSD specific
+            return FREEBSD_DEFAULT_FOLDERS[folder_type]
+        else:
+            # Linux specific
+            return LINUX_DEFAULT_FOLDERS[folder_type]
     # Windows specific
     return WINDOWS_DEFAULT_FOLDERS[folder_type]
 
