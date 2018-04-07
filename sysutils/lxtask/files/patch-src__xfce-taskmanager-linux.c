--- src/xfce-taskmanager-linux.c.orig	2011-06-21 21:50:00 UTC
+++ src/xfce-taskmanager-linux.c
@@ -29,6 +29,7 @@
 #include <glib/gprintf.h>
 #include "xfce-taskmanager-linux.h"
 
+#define PAGE_SIZE ( sysconf(_SC_PAGESIZE) )
 
 #if 1
 void get_task_details(gint pid,struct task *task)
@@ -40,7 +41,7 @@ void get_task_details(gint pid,struct ta
 	task->checked=FALSE;
         task->size=0;
 
-	sprintf(line,"/proc/%d/statm",pid);
+	sprintf(line,"/compat/linux/proc/%d/statm",pid);
         fd=open(line,O_RDONLY);
         if(fd==-1) return;
         read(fd,line,256);
@@ -50,7 +51,7 @@ void get_task_details(gint pid,struct ta
 	task->size*=PAGE_SIZE;
 	task->rss*=PAGE_SIZE;
 
-	sprintf(line,"/proc/%d/stat",pid);
+	sprintf(line,"/compat/linux/proc/%d/stat",pid);
 	fd=open(line,O_RDONLY);
 	if(fd!=-1)
 	{
@@ -136,8 +137,8 @@ struct task get_task_details(gint pid)
     gchar filename[255];
     gchar cmdline_filename[255];
 
-    sprintf(filename, "/proc/%i/stat", pid);
-    sprintf(cmdline_filename, "/proc/%i/cmdline", pid);
+    sprintf(filename, "/compat/linux/proc/%i/stat", pid);
+    sprintf(cmdline_filename, "/compat/linux/proc/%i/cmdline", pid);
 
     stat(filename, &status);
 
@@ -253,9 +254,9 @@ GArray *get_task_list(void)
     GArray *task_list;
     int count=0;
 
-    if((dir = opendir("/proc/")) == NULL)
+    if((dir = opendir("/compat/linux/proc/")) == NULL)
     {
-        fprintf(stderr, "Error: couldn't load the /proc directory\n");
+        fprintf(stderr, "Error: couldn't load the /compat/linux/proc directory\n");
         return NULL;
     }
 
@@ -295,7 +296,7 @@ GArray *get_task_list(void)
 
 
     task_list = g_array_new(FALSE, FALSE, sizeof (struct task));
-    n=scandir("/proc",&namelist,proc_filter,0);
+    n=scandir("/compat/linux/proc",&namelist,proc_filter,0);
     if(n<0) return task_list;
 
     g_array_set_size(task_list,n);
@@ -318,7 +319,7 @@ GArray *get_task_list(void)
 
 gboolean get_cpu_usage_from_proc(system_status *sys_stat)
 {
-    const gchar *file_name = "/proc/stat";
+    const gchar *file_name = "/compat/linux/proc/stat";
     FILE *file;
 
     if ( sys_stat->valid_proc_reading == TRUE ) {
@@ -359,7 +360,7 @@ gboolean get_system_status (system_statu
     int reach;
     static int cpu_count;
 
-    file = fopen ("/proc/meminfo", "r");
+    file = fopen ("/compat/linux/proc/meminfo", "r");
     if(!file) return FALSE;
     reach=0;
     while (fgets (buffer, 100, file) != NULL)
@@ -378,7 +379,7 @@ gboolean get_system_status (system_statu
 
     if(!cpu_count)
     {
-        file = fopen ("/proc/cpuinfo", "r");
+        file = fopen ("/compat/linux/proc/cpuinfo", "r");
         if(!file) return FALSE;
         while (fgets (buffer, 100, file) != NULL)
         {
