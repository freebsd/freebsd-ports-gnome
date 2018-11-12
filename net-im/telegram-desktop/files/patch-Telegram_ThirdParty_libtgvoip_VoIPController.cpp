--- Telegram/ThirdParty/libtgvoip/VoIPController.cpp.orig	2018-07-17 16:48:21 UTC
+++ Telegram/ThirdParty/libtgvoip/VoIPController.cpp
@@ -2048,7 +2048,7 @@ static void initMachTimestart() {
 #endif
 
 double VoIPController::GetCurrentTime(){
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 	struct timespec ts;
 	clock_gettime(CLOCK_MONOTONIC, &ts);
 	return ts.tv_sec+(double)ts.tv_nsec/1000000000.0;
