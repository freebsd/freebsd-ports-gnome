--- src/libide/gui/ide-gui-global.h.orig	2019-03-04 21:54:41 UTC
+++ src/libide/gui/ide-gui-global.h
@@ -30,7 +30,7 @@ G_BEGIN_DECLS
 #define ide_widget_warning(instance, format, ...)                                                   \
   G_STMT_START {                                                                                    \
     IdeContext *context = ide_widget_get_context (GTK_WIDGET (instance));                           \
-    ide_context_log (context, G_LOG_LEVEL_WARNING, G_LOG_DOMAIN, format __VA_OPT__(,) __VA_ARGS__); \
+    ide_context_log (context, G_LOG_LEVEL_WARNING, G_LOG_DOMAIN, format, ## __VA_ARGS__); \
   } G_STMT_END
 
 typedef void (*IdeWidgetContextHandler) (GtkWidget  *widget,
