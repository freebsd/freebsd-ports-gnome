removeEmptyLines() segfaults on empty string

https://bugs.gentoo.org/show_bug.cgi?id=454348
http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=676423

Patch written by Thibaut Paumard <paumard@users.sourceforge.net>
--- src/htmlgen.cpp
+++ src/htmlgen.cpp
@@ -1022,6 +1022,11 @@
 static QCString removeEmptyLines(const QCString &s)
 {
   BufStr out(s.length()+1);
+  if (s.length()==0)
+  {
+    out.addChar('\0');
+    return out.data();
+  }
   const char *p=s.data();
   if (p)
   {
