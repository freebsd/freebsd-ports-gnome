--- src/lsof.cpp.orig	2015-09-25 13:36:19.000000000 +0200
+++ src/lsof.cpp	2016-01-09 12:24:55.546084000 +0100
@@ -140,7 +140,7 @@
 
         void update_count(unsigned count)
         {
-            string s = static_cast<std::ostringstream&>(std::ostringstream() << count).str();
+            string s = static_cast<std::ostringstream&>(std::ostringstream().flush() << count).str();
             gtk_label_set_text(this->count, s.c_str());
         }
 
