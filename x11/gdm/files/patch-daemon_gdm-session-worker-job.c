--- daemon/gdm-session-worker-job.c.orig	2015-08-16 16:56:01 UTC
+++ daemon/gdm-session-worker-job.c
@@ -36,7 +36,9 @@
 #include <sys/prctl.h>
 #endif
 
+#ifdef WITH_SYSTEMD
 #include <systemd/sd-daemon.h>
+#endif
 
 #ifdef ENABLE_SYSTEMD_JOURNAL
 #include <systemd/sd-journal.h>
