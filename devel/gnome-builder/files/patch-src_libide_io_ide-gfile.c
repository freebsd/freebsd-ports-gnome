--- src/libide/io/ide-gfile.c.orig	2019-02-19 02:44:09 UTC
+++ src/libide/io/ide-gfile.c
@@ -366,7 +366,7 @@ ide_g_file_get_children_async (GFile               *fi
   ide_task_set_priority (task, io_priority);
   ide_task_set_task_data (task, gc, get_children_free);
 
-#ifdef DEVELOPMENT_BUILD
+#if 0 //def DEVELOPMENT_BUILD
   /* Useful for testing slow interactions on project-tree and such */
   if (g_getenv ("IDE_G_FILE_DELAY"))
     {
