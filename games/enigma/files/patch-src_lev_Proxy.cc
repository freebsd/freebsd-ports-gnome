--- src/lev/Proxy.cc.orig	2017-09-03 15:54:50 UTC
+++ src/lev/Proxy.cc
@@ -933,7 +933,7 @@ namespace enigma { namespace lev {
                     } else if (haveLocalCopy) {
                         // plain file
                         basic_ifstream<char> ifs(absExtPath.c_str(), ios::binary | ios::in);
-                        if (ifs != NULL)
+                        if (ifs)
                             Readfile(ifs, extCode);
                         else
                             haveLocalCopy = false;
