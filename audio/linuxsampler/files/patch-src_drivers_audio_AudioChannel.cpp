--- src/drivers/audio/AudioChannel.cpp.orig	2012-10-04 18:16:26 UTC
+++ src/drivers/audio/AudioChannel.cpp
@@ -26,7 +26,7 @@
 #include "../../common/global_private.h"
 #include "../../common/Thread.h" // needed for allocAlignedMem() and freeAlignedMem()
 
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 # include <stdlib.h>
 #else
 # include <malloc.h>
