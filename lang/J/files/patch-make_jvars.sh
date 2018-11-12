--- make/jvars.sh.orig	2018-04-09 18:05:09 UTC
+++ make/jvars.sh
@@ -1,11 +1,11 @@
 # source shell script (read with . jvars.sh) so stuff is easy to find
 
 # edit following if your install is not standard 
-jgit=~/gitdev/jsource # git jsource folder
+jgit=~/jsource-j808-release # git jsource folder
 jbld=~/jbld           # test libraries and binaries will be put here
 
 # edit platform to build - linux darwin raspberry
-jplatform=linux
+jplatform=freebsd
 
 # should not be necessary to edit after here
 j32=$jbld/j32/bin/jconsole
