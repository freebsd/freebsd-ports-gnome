--- src/libide/core/ide-object.h.orig	2019-03-04 21:52:37 UTC
+++ src/libide/core/ide-object.h
@@ -150,7 +150,7 @@ void          ide_object_log                    (gpoin
                                                  const gchar        *format,
                                                  ...) G_GNUC_PRINTF (4, 5);
 
-#define ide_object_message(instance, format, ...) ide_object_log(instance, G_LOG_LEVEL_MESSAGE, G_LOG_DOMAIN, format __VA_OPT__(,) __VA_ARGS__)
-#define ide_object_warning(instance, format, ...) ide_object_log(instance, G_LOG_LEVEL_WARNING, G_LOG_DOMAIN, format __VA_OPT__(,) __VA_ARGS__)
+#define ide_object_message(instance, format, ...) ide_object_log(instance, G_LOG_LEVEL_MESSAGE, G_LOG_DOMAIN, format, ## __VA_ARGS__)
+#define ide_object_warning(instance, format, ...) ide_object_log(instance, G_LOG_LEVEL_WARNING, G_LOG_DOMAIN, format, ## __VA_ARGS__)
 
 G_END_DECLS
