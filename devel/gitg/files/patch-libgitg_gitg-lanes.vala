From 358f5ec7e94ffd80a16321de9ecdb8ca3a5138be Mon Sep 17 00:00:00 2001
From: Rico Tzschichholz <ricotz@ubuntu.com>
Date: Sun, 4 Nov 2018 15:13:49 +0100
Subject: [PATCH] libgitg: Fix mismatch of type-parameter ownership

---
 libgitg/gitg-lanes.vala | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)

diff --git a/libgitg/gitg-lanes.vala b/libgitg/gitg-lanes.vala
index 780fa092..1af72e05 100644
--- libgitg/gitg-lanes.vala
+++ libgitg/gitg-lanes.vala
@@ -469,7 +469,7 @@ public class Lanes : Object
 		index = next;
 		uint cnt = 0;
 
-		unowned SList<Commit> ptr = d_previous;
+		unowned SList<weak Commit> ptr = d_previous;
 
 		while (ptr != null)
 		{
-- 
2.18.1

