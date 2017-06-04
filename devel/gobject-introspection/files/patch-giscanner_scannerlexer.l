--- giscanner/scannerlexer.l	2016-07-29 08:32:43.000000000 +0300
+++ giscanner/scannerlexer.l	2017-04-06 01:03:53.123501000 +0300
@@ -164,6 +164,8 @@ 
 "__inline__"                            { return INLINE; }
 "__inline"				{ return INLINE; }
 "__nonnull" 			        { if (!parse_ignored_macro()) REJECT; }
+"_Nonnull" 			        { /* Ignore */ }
+"_Nullable" 			        { /* Ignore */ }
 "_Noreturn" 			        { /* Ignore */ }
 "__signed"                              { return SIGNED; }
 "__signed__"				{ return SIGNED; }
