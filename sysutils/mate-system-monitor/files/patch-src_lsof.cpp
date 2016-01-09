--- src/lsof.cpp.orig	2016-01-09 12:10:26.760298000 +0100
+++ src/lsof.cpp	2016-01-09 12:10:37.441213000 +0100
@@ -140,7 +140,7 @@
 
         void update_count(unsigned count)
         {
-            string s = static_cast<std::ostringstream&>(std::ostringstream() << count).str();
+            string s = (std::ostringstream() << count).str();
             gtk_label_set_text(this->count, s.c_str());
         }
 
