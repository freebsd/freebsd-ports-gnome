--- cfg/global_vars.mk.orig	2018-02-27 23:46:56 UTC
+++ cfg/global_vars.mk
@@ -1,11 +1,7 @@
 # Version
-TOXIC_VERSION = 0.8.1
-REV = $(shell git rev-list HEAD --count 2>/dev/null || echo -n "error")
-ifneq (, $(findstring error, $(REV)))
-    VERSION = $(TOXIC_VERSION)
-else
-    VERSION = $(TOXIC_VERSION)_r$(REV)
-endif
+TOXIC_VERSION = 0.8.2
+#REV = $(shell git rev-list HEAD --count 2>/dev/null || echo -n "error")
+VERSION = $(TOXIC_VERSION)
 
 # Project directories
 BUILD_DIR = $(BASE_DIR)/build
