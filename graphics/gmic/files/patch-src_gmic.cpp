--- src/gmic.cpp.orig	2018-05-30 23:49:53 UTC
+++ src/gmic.cpp
@@ -2224,7 +2224,7 @@ double gmic::mp_ext(char *const str, voi
 // Manage correspondence between abort pointers and thread ids.
 CImgList<void*> gmic::list_p_is_abort = CImgList<void*>();
 bool *gmic::abort_ptr(bool *const p_is_abort) {
-#if defined(__MACOSX__) || defined(__APPLE__)
+#if defined(__MACOSX__) || defined(__APPLE__) || defined(__FreeBSD__)
   void* tid = (void*)(cimg_ulong)getpid();
 #elif cimg_OS==1
   void* tid = (void*)(cimg_ulong)syscall(SYS_gettid);
@@ -2557,7 +2557,7 @@ gmic::~gmic() {
 #endif // #if cimg_display!=0
 
   cimg::mutex(21);
-#if defined(__MACOSX__) || defined(__APPLE__)
+#if defined(__MACOSX__) || defined(__APPLE__) || defined(__FreeBSD__)
   void* tid = (void*)(cimg_ulong)getpid();
 #elif cimg_OS==1
   void* tid = (void*)(cimg_ulong)syscall(SYS_gettid);
