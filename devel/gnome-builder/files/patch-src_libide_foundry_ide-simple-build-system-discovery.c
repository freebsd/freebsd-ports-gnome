--- src/libide/foundry/ide-simple-build-system-discovery.c.orig	2019-07-28 08:23:10 UTC
+++ src/libide/foundry/ide-simple-build-system-discovery.c
@@ -289,7 +289,12 @@ ide_simple_build_system_discovery_match (IdeSimpleBuil
   g_assert (IDE_IS_SIMPLE_BUILD_SYSTEM_DISCOVERY (self));
   g_assert (name != NULL);
 
+
+#if defined(FNM_EXTMATCH)
   return fnmatch (priv->glob, name, FNM_EXTMATCH) == 0;
+#else
+  return fnmatch (priv->glob, name, 0) == 0;
+#endif
 }
 
 static gboolean
