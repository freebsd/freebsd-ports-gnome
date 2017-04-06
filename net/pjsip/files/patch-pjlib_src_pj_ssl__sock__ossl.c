--- pjlib/src/pj/ssl_sock_ossl.c.orig	2017-01-24 05:41:05 UTC
+++ pjlib/src/pj/ssl_sock_ossl.c
@@ -54,7 +54,7 @@
 #include <openssl/engine.h>
 #include <openssl/opensslconf.h>
 
-#if !defined(OPENSSL_NO_EC) && OPENSSL_VERSION_NUMBER >= 0x1000200fL
+#if !defined(OPENSSL_NO_EC) && OPENSSL_VERSION_NUMBER >= 0x1000200fL && !defined(LIBRESSL_VERSION_NUMBER)
 
 #   include <openssl/obj_mac.h>
 
@@ -112,7 +112,7 @@ static unsigned get_nid_from_cid(unsigne
 #endif
 
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 #  define OPENSSL_NO_SSL2	    /* seems to be removed in 1.1.0 */
 #  define M_ASN1_STRING_data(x)	    ASN1_STRING_get0_data(x)
 #  define M_ASN1_STRING_length(x)   ASN1_STRING_length(x)
@@ -452,7 +452,7 @@ static pj_status_t init_openssl(void)
 
 	SSL_set_session(ssl, SSL_SESSION_new());
 
-#if !defined(OPENSSL_NO_EC) && OPENSSL_VERSION_NUMBER >= 0x1000200fL
+#if !defined(OPENSSL_NO_EC) && OPENSSL_VERSION_NUMBER >= 0x1000200fL && !defined(LIBRESSL_VERSION_NUMBER)
 	openssl_curves_num = SSL_get_shared_curve(ssl,-1);
 	if (openssl_curves_num > PJ_ARRAY_SIZE(openssl_curves))
 	    openssl_curves_num = PJ_ARRAY_SIZE(openssl_curves);
@@ -1069,7 +1069,7 @@ static pj_status_t set_cipher_list(pj_ss
 
 static pj_status_t set_curves_list(pj_ssl_sock_t *ssock)
 {
-#if !defined(OPENSSL_NO_EC) && OPENSSL_VERSION_NUMBER >= 0x1000200fL
+#if !defined(OPENSSL_NO_EC) && OPENSSL_VERSION_NUMBER >= 0x1000200fL && !defined(LIBRESSL_VERSION_NUMBER)
     int ret;
     int curves[PJ_SSL_SOCK_MAX_CURVES];
     unsigned cnt;
@@ -1100,7 +1100,7 @@ static pj_status_t set_curves_list(pj_ss
 
 static pj_status_t set_sigalgs(pj_ssl_sock_t *ssock)
 {
-#if OPENSSL_VERSION_NUMBER >= 0x1000200fL
+#if OPENSSL_VERSION_NUMBER >= 0x1000200fL && !defined(LIBRESSL_VERSION_NUMBER)
     int ret;
 
     if (ssock->param.sigalgs.ptr && ssock->param.sigalgs.slen) {
