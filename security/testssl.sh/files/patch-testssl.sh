--- testssl.sh.orig	2017-11-05 21:50:58 UTC
+++ testssl.sh
@@ -164,6 +164,9 @@ TERM_CURRPOS=0                          
 ## CONFIGURATION PART ##
 # following variables make use of $ENV, e.g. OPENSSL=<myprivate_path_to_openssl> ./testssl.sh <host>
 # 0 means (normally) true here. Some of the variables are also accessible with a command line switch, see --help
+if [[ -z "$OPENSSL" ]] ; then
+     OPENSSL=PREFIX/openssl-unsafe/bin/openssl
+fi
 declare -x OPENSSL OPENSSL_TIMEOUT
 FAST_SOCKET=${FAST_SOCKET:-false}       # EXPERIMENTAL feature to accelerate sockets -- DO NOT USE it for production
 COLOR=${COLOR:-2}                       # 2: Full color, 1: b/w+positioning, 0: no ESC at all
