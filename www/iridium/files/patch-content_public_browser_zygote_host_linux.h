--- content/public/browser/zygote_host_linux.h.orig	2018-08-16 15:32:17.788486000 +0200
+++ content/public/browser/zygote_host_linux.h	2018-08-16 15:32:45.497597000 +0200
@@ -30,11 +30,13 @@
   // after the first render has been forked.
   virtual int GetRendererSandboxStatus() const = 0;
 
+#if !defined(OS_BSD)
   // Adjust the OOM score of the given renderer's PID.  The allowed
   // range for the score is [0, 1000], where higher values are more
   // likely to be killed by the OOM killer.
   virtual void AdjustRendererOOMScore(base::ProcessHandle process_handle,
                                       int score) = 0;
+#endif
 };
 
 }  // namespace content
