--- vm_trace.c.orig	2015-12-14 02:52:14 UTC
+++ vm_trace.c
@@ -389,7 +389,7 @@ rb_suppress_tracing(VALUE (*func)(VALUE)
     volatile int raised;
     volatile int outer_state;
     VALUE result = Qnil;
-    rb_thread_t *th = GET_THREAD();
+    rb_thread_t *volatile th = GET_THREAD();
     int state;
     const int tracing = th->trace_arg ? 1 : 0;
     rb_trace_arg_t dummy_trace_arg;
