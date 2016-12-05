--- daemon/gdm-session.c.orig	2015-08-16 16:56:01 UTC
+++ daemon/gdm-session.c
@@ -3039,6 +3039,10 @@ gdm_session_get_display_mode (GdmSession
                  self->priv->is_program_session? "yes" : "no",
                  self->priv->display_seat_id);
 
+        if (!LOGIND_RUNNING()) {
+                return GDM_SESSION_DISPLAY_MODE_REUSE_VT;
+        }
+
 #ifdef ENABLE_WAYLAND_SUPPORT
         /* Wayland sessions are for now assumed to run in a
          * mutter-launch-like environment, so we allocate
@@ -3080,6 +3084,27 @@ gdm_session_select_program (GdmSession *
 }
 
 void
+gdm_session_select_session_type (GdmSession *self,
+                                 const char *text)
+{
+        GHashTableIter iter;
+        gpointer key, value;
+
+        g_debug ("GdmSession: selecting session type '%s'", text);
+
+        g_hash_table_iter_init (&iter, self->priv->conversations);
+        while (g_hash_table_iter_next (&iter, &key, &value)) {
+                GdmSessionConversation *conversation;
+
+                conversation = (GdmSessionConversation *) value;
+
+                gdm_dbus_worker_call_set_session_type (conversation->worker_proxy,
+                                                       text,
+                                                       NULL, NULL, NULL);
+        }
+}
+
+void
 gdm_session_select_session (GdmSession *self,
                             const char *text)
 {
