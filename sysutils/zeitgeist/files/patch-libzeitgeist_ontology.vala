From cc4603a2b5d9e6f36d196432042f6f0048dd5d89 Mon Sep 17 00:00:00 2001
From: Rico Tzschichholz <ricotz@ubuntu.com>
Date: Thu, 5 Apr 2018 13:12:51 +0200
Subject: [PATCH] ontology: Avoid ownership mismatches of container elements to
 fix memleak

---
 libzeitgeist/ontology.vala.in | 10 +++++-----
 1 file changed, 5 insertions(+), 5 deletions(-)

diff --git a/libzeitgeist/ontology.vala.in b/libzeitgeist/ontology.vala.in
index 63171701..768fd005 100644
--- libzeitgeist/ontology.vala.in
+++ libzeitgeist/ontology.vala.in
@@ -56,7 +56,7 @@ namespace Zeitgeist
         {
             initialize_symbols ();
 
-            var results = new List<string> ();
+            var results = new List<unowned string> ();
             var symbol = all_symbols.lookup (symbol_uri);
             if (symbol == null) return results;
 
@@ -64,7 +64,7 @@ namespace Zeitgeist
             {
                 results.append (uri);
                 // Recursively get the other parents
-                foreach (string parent_uri in get_all_parents (uri))
+                foreach (unowned string parent_uri in get_all_parents (uri))
                     if (results.index (parent_uri) == -1)
                         results.append (parent_uri);
             }
@@ -76,7 +76,7 @@ namespace Zeitgeist
         {
             initialize_symbols ();
 
-            var results = new List<string> ();
+            var results = new List<unowned string> ();
             var symbol = all_symbols.lookup (symbol_uri);
             if (symbol == null) return results;
 
@@ -89,7 +89,7 @@ namespace Zeitgeist
         public static List<unowned string> get_children (string symbol_uri)
         {
             initialize_symbols ();
-            var results = new List<string> ();
+            var results = new List<unowned string> ();
             var symbol = all_symbols.lookup (symbol_uri);
             if (symbol == null) return results;
 
@@ -103,7 +103,7 @@ namespace Zeitgeist
         {
             initialize_symbols ();
 
-            var results = new List<string>();
+            var results = new List<unowned string>();
             var symbol = all_symbols.lookup (symbol_uri);
             if (symbol == null) return results;
 
-- 
2.18.1

