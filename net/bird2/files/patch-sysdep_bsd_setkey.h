--- sysdep/bsd/setkey.h.orig	2018-01-16 09:46:07 UTC
+++ sysdep/bsd/setkey.h
@@ -160,12 +160,14 @@ sk_set_md5_in_sasp_db(sock *s, ip_addr local, ip_addr 
     if (len > TCP_KEYLEN_MAX)
       ERR_MSG("The password for TCP MD5 Signature is too long");
 
-    if (setkey_md5(&src, &dst, pxlen, passwd, SADB_ADD) < 0)
+    if (setkey_md5(&src, &dst, pxlen, passwd, SADB_ADD) < 0 ||
+		setkey_md5(&dst, &src, pxlen, passwd, SADB_ADD) < 0)
       ERR_MSG("Cannot add TCP-MD5 password into the IPsec SA/SP database");
   }
   else
   {
-    if (setkey_md5(&src, &dst, pxlen, NULL, SADB_DELETE) < 0)
+    if (setkey_md5(&src, &dst, pxlen, NULL, SADB_DELETE) < 0 ||
+		setkey_md5(&dst, &src, pxlen, NULL, SADB_DELETE) < 0)
       ERR_MSG("Cannot delete TCP-MD5 password from the IPsec SA/SP database");
   }
   return 0;
