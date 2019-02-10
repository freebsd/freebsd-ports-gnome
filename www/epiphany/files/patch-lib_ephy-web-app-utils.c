--- lib/ephy-web-app-utils.c.orig	2019-02-10 21:59:16 UTC
+++ lib/ephy-web-app-utils.c
@@ -345,6 +345,9 @@ ephy_web_application_create (const char *id,
   char *profile_dir;
   char *desktop_file_path = NULL;
 
+  /* Create an .app file. */
+  g_autofree char *app_file = g_build_filename (profile_dir, ".app", NULL);
+
   /* If there's already a WebApp profile for the contents of this
    * view, do nothing. */
   profile_dir = ephy_web_application_get_profile_directory (id);
@@ -360,7 +363,6 @@ ephy_web_application_create (const char *id,
   }
 
   /* Create an .app file. */
-  g_autofree char *app_file = g_build_filename (profile_dir, ".app", NULL);
   int fd = g_open (app_file, O_WRONLY|O_CREAT|O_TRUNC, 0644);
   if (fd < 0) {
     LOG ("Failed to create .app file: %s", g_strerror (errno));
