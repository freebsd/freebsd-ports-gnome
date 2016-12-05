--- daemon/gdm-session.h.orig	2015-07-20 13:13:42 UTC
+++ daemon/gdm-session.h
@@ -176,6 +176,8 @@ void              gdm_session_answer_que
                                                            const char *text);
 void              gdm_session_select_program              (GdmSession *session,
                                                            const char *command_line);
+void              gdm_session_select_session_type         (GdmSession *session,
+                                                           const char *session_type);
 void              gdm_session_select_session              (GdmSession *session,
                                                            const char *session_name);
 void              gdm_session_select_user                 (GdmSession *session,
