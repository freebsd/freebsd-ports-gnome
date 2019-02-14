--- plugins/eds/gtd-eds-autoptr.h.orig	2019-02-14 20:18:26 UTC
+++ plugins/eds/gtd-eds-autoptr.h
@@ -25,4 +25,3 @@
 G_DEFINE_AUTOPTR_CLEANUP_FUNC (ECalComponent, g_object_unref);
 G_DEFINE_AUTOPTR_CLEANUP_FUNC (ECalComponentId, e_cal_component_free_id);
 G_DEFINE_AUTOPTR_CLEANUP_FUNC (ECalClient, g_object_unref);
-G_DEFINE_AUTOPTR_CLEANUP_FUNC (ESource, g_object_unref);
