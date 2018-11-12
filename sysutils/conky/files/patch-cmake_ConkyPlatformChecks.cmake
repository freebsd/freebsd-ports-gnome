diff --git a/cmake/ConkyPlatformChecks.cmake b/cmake/ConkyPlatformChecks.cmake
index 334b4690..ce5c109b 100644
--- cmake/ConkyPlatformChecks.cmake
+++ cmake/ConkyPlatformChecks.cmake
@@ -30,8 +30,6 @@ check_include_files(sys/statfs.h HAVE_SYS_STATFS_H)
 check_include_files(sys/param.h HAVE_SYS_PARAM_H)
 check_include_files(sys/inotify.h HAVE_SYS_INOTIFY_H)
 check_include_files(dirent.h HAVE_DIRENT_H)
-check_include_files("soundcard.h;sys/soundcard.h;linux/soundcard.h" HAVE_SOME_SOUNDCARD_H)
-check_include_files("linux/soundcard.h" HAVE_LINUX_SOUNDCARD_H)
 
 # Check for some functions
 check_function_exists(strndup HAVE_STRNDUP)
@@ -88,6 +86,16 @@ if(NOT OS_LINUX AND NOT OS_FREEBSD AND NOT OS_OPENBSD AND NOT OS_DRAGONFLY
 endif(NOT OS_LINUX AND NOT OS_FREEBSD AND NOT OS_OPENBSD AND NOT OS_DRAGONFLY
   AND NOT OS_SOLARIS AND NOT OS_HAIKU)
 
+# Check for soundcard header
+if(OS_LINUX)
+	check_include_files("linux/soundcard.h" HAVE_SOME_SOUNDCARD_H)
+	check_include_files("linux/soundcard.h" HAVE_LINUX_SOUNDCARD_H)
+elseif(OS_OPENBSD)
+	check_include_files("soundcard.h" HAVE_SOME_SOUNDCARD_H)
+else(OS_LINUX)
+	check_include_files("sys/soundcard.h" HAVE_SOME_SOUNDCARD_H)
+endif(OS_LINUX)
+
 if(BUILD_I18N AND OS_DRAGONFLY)
 	set(conky_libs ${conky_libs} -lintl)
 endif(BUILD_I18N AND OS_DRAGONFLY)
