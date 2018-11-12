--- components/services/filesystem/file_system_app.cc.orig	2018-08-01 00:08:40.000000000 +0200
+++ components/services/filesystem/file_system_app.cc	2018-08-04 18:24:22.212419000 +0200
@@ -20,7 +20,7 @@
 #elif defined(OS_ANDROID)
 #include "base/base_paths_android.h"
 #include "base/path_service.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "base/environment.h"
 #include "base/nix/xdg_util.h"
 #elif defined(OS_MACOSX)
@@ -75,7 +75,7 @@
     CHECK(base::PathService::Get(base::DIR_APP_DATA, &path));
 #elif defined(OS_ANDROID)
     CHECK(base::PathService::Get(base::DIR_ANDROID_APP_DATA, &path));
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
     std::unique_ptr<base::Environment> env(base::Environment::Create());
     path = base::nix::GetXDGDirectory(
         env.get(), base::nix::kXdgConfigHomeEnvVar, base::nix::kDotConfigDir);
