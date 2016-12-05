--- common/gdm-common.h.orig	2015-07-20 13:13:40 UTC
+++ common/gdm-common.h
@@ -33,6 +33,9 @@
 
 #define GDM_CUSTOM_SESSION  "custom"
 
+/* check if logind is running */
+#define LOGIND_RUNNING() (access("/run/systemd/seats/", F_OK) >= 0)
+
 GQuark gdm_common_error_quark (void);
 #define GDM_COMMON_ERROR gdm_common_error_quark()
 
