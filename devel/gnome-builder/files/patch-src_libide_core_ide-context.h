--- src/libide/core/ide-context.h.orig	2019-03-04 21:53:58 UTC
+++ src/libide/core/ide-context.h
@@ -86,6 +86,6 @@ void        ide_context_log                  (IdeConte
                                               const gchar    *message);
 
 #define ide_context_warning(instance, format, ...) \
-  ide_object_log(instance, G_LOG_LEVEL_WARNING, G_LOG_DOMAIN, format __VA_OPT__(,) __VA_ARGS__)
+  ide_object_log(instance, G_LOG_LEVEL_WARNING, G_LOG_DOMAIN, format, ## __VA_ARGS__)
 
 G_END_DECLS
