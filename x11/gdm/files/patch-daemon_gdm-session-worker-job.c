$OpenBSD: patch-daemon_gdm-session-worker-job_c,v 1.1 2015/10/18 13:25:54 ajacoutot Exp $

REVERT - OpenBSD does not have a systemd implementation (we need ConsoleKit)
From 9be58c9ec9a3a411492a5182ac4b0d51fdc3a323 Mon Sep 17 00:00:00 2001
From: Ray Strode <rstrode@redhat.com>
Date: Fri, 12 Jun 2015 13:48:52 -0400
Subject: require logind support

--- daemon/gdm-session-worker-job.c.orig	2019-02-21 19:44:14 UTC
+++ daemon/gdm-session-worker-job.c
@@ -36,7 +36,9 @@
 #include <sys/prctl.h>
 #endif
 
+#ifdef WITH_SYSTEMD
 #include <systemd/sd-daemon.h>
+#endif
 
 #ifdef ENABLE_SYSTEMD_JOURNAL
 #include <systemd/sd-journal.h>
