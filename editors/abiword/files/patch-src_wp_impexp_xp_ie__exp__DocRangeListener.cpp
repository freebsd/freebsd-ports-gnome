--- src/wp/impexp/xp/ie_exp_DocRangeListener.cpp.orig	2013-04-07 13:53:03 UTC
+++ src/wp/impexp/xp/ie_exp_DocRangeListener.cpp
@@ -166,7 +166,7 @@ void  IE_Exp_DocRangeListener::freeAtts(const char ***
   UT_sint32 i=0;
   while(sAtts[i])
   {
-      delete [] (sAtts[i]);
+      g_free(const_cast<char*>(sAtts[i]));
       i++;
   }
   delete [] sAtts;
