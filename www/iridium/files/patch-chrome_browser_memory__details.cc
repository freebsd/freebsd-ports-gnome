--- chrome/browser/memory_details.cc.orig	2018-05-09 21:05:38.000000000 +0200
+++ chrome/browser/memory_details.cc	2018-08-16 08:40:29.413255000 +0200
@@ -36,7 +36,7 @@
 #include "services/resource_coordinator/public/cpp/memory_instrumentation/memory_instrumentation.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 #include "content/public/browser/zygote_host_linux.h"
 #endif
 
@@ -341,7 +341,7 @@
       process.titles.push_back(title);
     }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
     if (content::ZygoteHost::GetInstance()->IsZygotePid(process.pid)) {
       process.process_type = content::PROCESS_TYPE_ZYGOTE;
     }
