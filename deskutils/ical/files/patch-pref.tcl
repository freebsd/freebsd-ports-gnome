--- pref.tcl.orig	1997-06-12 22:50:36 UTC
+++ pref.tcl
@@ -118,7 +118,12 @@ proc pref_init {} {
     # XXX People do not seem to like the motif-style popup behavior
     global tk_strictMotif
     if {!$tk_strictMotif} {
-	bind Menubutton <Any-ButtonRelease-1> {tkMenuUnpost {}}
+	set tv [info tclversion]
+	if {[package vcompare $tv 8.4] >= 0} {
+	    bind Menubutton <Any-ButtonRelease-1> {::tk::MenuUnpost {}}
+	} else {
+	    bind Menubutton <Any-ButtonRelease-1> {tkMenuUnpost {}}
+	}
     }
 
     # Handle command line preferences
