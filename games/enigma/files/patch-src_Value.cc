--- src/Value.cc.orig	2017-09-03 15:39:37 UTC
+++ src/Value.cc
@@ -146,10 +146,10 @@ namespace enigma {
                 val.str[0] = 0;
                 break;
             case BOOL :
-                val.dval[0] = false;
+                val.dval[0] = 0;
                 break;
             case OBJECT :
-                val.dval[0] = (double) NULL;
+                val.dval[0] = 0;
                 break;
             case NAMEDOBJECT:
                 ASSERT(false, XLevelRuntime, "Value: illegal type usage");
