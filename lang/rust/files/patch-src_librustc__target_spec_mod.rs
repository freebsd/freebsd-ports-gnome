--- src/librustc_target/spec/mod.rs.orig	2019-01-16 09:30:27 UTC
+++ src/librustc_target/spec/mod.rs
@@ -333,7 +333,10 @@ supported_targets! {
     ("aarch64-linux-android", aarch64_linux_android),
 
     ("aarch64-unknown-freebsd", aarch64_unknown_freebsd),
+    ("armv6-unknown-freebsd", armv6_unknown_freebsd),
+    ("armv7-unknown-freebsd", armv7_unknown_freebsd),
     ("i686-unknown-freebsd", i686_unknown_freebsd),
+    ("powerpc64-unknown-freebsd", powerpc64_unknown_freebsd),
     ("x86_64-unknown-freebsd", x86_64_unknown_freebsd),
 
     ("i686-unknown-dragonfly", i686_unknown_dragonfly),
