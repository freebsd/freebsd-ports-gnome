--- content/zygote/zygote_main_linux.cc.orig	2018-08-16 15:24:32.575502000 +0200
+++ content/zygote/zygote_main_linux.cc	2018-08-16 15:26:32.569493000 +0200
@@ -11,7 +11,9 @@
 #include <stddef.h>
 #include <stdint.h>
 #include <string.h>
+#if !defined(OS_BSD)
 #include <sys/prctl.h>
+#endif
 #include <sys/socket.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -101,6 +103,7 @@
 // created through the setuid sandbox.
 static bool EnterSuidSandbox(sandbox::SetuidSandboxClient* setuid_sandbox,
                              base::OnceClosure post_fork_parent_callback) {
+#if !defined(OS_BSD)
   DCHECK(setuid_sandbox);
   DCHECK(setuid_sandbox->IsSuidSandboxChild());
 
@@ -133,6 +136,9 @@
 
   CHECK(service_manager::SandboxDebugHandling::SetDumpableStatusAndHandlers());
   return true;
+#else
+  return false;
+#endif
 }
 
 static void DropAllCapabilities(int proc_fd) {
@@ -178,6 +184,7 @@
 
 bool ZygoteMain(
     std::vector<std::unique_ptr<ZygoteForkDelegate>> fork_delegates) {
+#if !defined(OS_BSD)
   sandbox::SetAmZygoteOrRenderer(true, GetSandboxFD());
 
   auto* linux_sandbox = service_manager::SandboxLinux::GetInstance();
@@ -239,6 +246,9 @@
 
   // This function call can return multiple times, once per fork().
   return zygote.ProcessRequests();
+#else
+  return false;
+#endif
 }
 
 }  // namespace content
