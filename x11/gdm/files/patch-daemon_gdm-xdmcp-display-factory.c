--- daemon/gdm-xdmcp-display-factory.c.orig	2019-02-26 19:56:53 UTC
+++ daemon/gdm-xdmcp-display-factory.c
@@ -75,7 +75,7 @@ int deny_severity = LOG_WARNING;
 #define DEFAULT_USE_MULTICAST         FALSE
 #define DEFAULT_MULTICAST_ADDRESS     "ff02::1"
 #define DEFAULT_HONOR_INDIRECT        TRUE
-#define DEFAULT_MAX_DISPLAYS_PER_HOST 1
+#define DEFAULT_MAX_DISPLAYS_PER_HOST 2
 #define DEFAULT_MAX_DISPLAYS          16
 #define DEFAULT_MAX_PENDING_DISPLAYS  4
 #define DEFAULT_MAX_WAIT              30
