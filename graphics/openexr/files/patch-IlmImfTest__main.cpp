--- IlmImfTest/main.cpp.orig	2014-08-10 04:23:59 UTC
+++ IlmImfTest/main.cpp
@@ -100,7 +100,7 @@
 #include <string.h>
 #include <time.h>
 
-#if defined(OPENEXR_IMF_HAVE_LINUX_PROCFS) || defined(OPENEXR_IMF_HAVE_DARWIN)
+#if defined(OPENEXR_IMF_HAVE_LINUX_PROCFS) || defined(OPENEXR_IMF_HAVE_DARWIN) || defined(__FreeBSD__)
     #include <unistd.h>
     #include <sstream>
 #endif
