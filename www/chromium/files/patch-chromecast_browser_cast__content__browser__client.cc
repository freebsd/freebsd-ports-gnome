--- chromecast/browser/cast_content_browser_client.cc.orig	2017-03-09 20:04:31 UTC
+++ chromecast/browser/cast_content_browser_client.cc
@@ -285,7 +285,7 @@ void CastContentBrowserClient::AppendExt
       command_line->AppendSwitch(switches::kAllowHiddenMediaPlayback);
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Necessary for accelerated 2d canvas.  By default on Linux, Chromium assumes
   // GLES2 contexts can be lost to a power-save mode, which breaks GPU canvas
   // apps.
