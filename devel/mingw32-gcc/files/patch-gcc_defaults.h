--- gcc/defaults.h.orig	2013-01-10 20:38:27 UTC
+++ gcc/defaults.h
@@ -123,7 +123,7 @@ see the files COPYING3 and COPYING.RUNTI
     {									\
       fprintf ((FILE), "\t%s\t", TLS_COMMON_ASM_OP);			\
       assemble_name ((FILE), (NAME));					\
-      fprintf ((FILE), ","HOST_WIDE_INT_PRINT_UNSIGNED",%u\n",		\
+      fprintf ((FILE), "," HOST_WIDE_INT_PRINT_UNSIGNED ",%u\n",		\
 	       (SIZE), DECL_ALIGN (DECL) / BITS_PER_UNIT);		\
     }									\
   while (0)
