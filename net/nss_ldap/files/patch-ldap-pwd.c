--- ldap-pwd.c.orig
+++ ldap-pwd.c
@@ -21,7 +21,10 @@
 static char rcsId[] =
   "$Id: ldap-pwd.c,v 2.48 2008/10/30 20:49:47 lukeh Exp $";
 
+#include <sys/types.h>
+#include <unistd.h>
 #include "config.h"
+ 
 
 #ifdef HAVE_PORT_BEFORE_H
 #include <port_before.h>
@@ -90,9 +93,13 @@
   size_t tmplen;
   char *tmp;
 
-  if (_nss_ldap_oc_check (e, "shadowAccount") == NSS_SUCCESS)
-    {
+/*  if (_nss_ldap_oc_check (e, "shadowAccount") == NSS_SUCCESS)
+ *   {
+ */
       /* don't include password for shadowAccount */
+  if (geteuid() != 0) 
+  {
+	  /* don't include password for non-root users */
       if (buflen < 3)
 	return NSS_TRYAGAIN;
 
