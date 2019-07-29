Fix the build

--- plugin/pango/gvtextlayout_pango.c.orig	2019-07-29 21:38:59 UTC
+++ plugin/pango/gvtextlayout_pango.c
@@ -24,6 +24,9 @@
 #include <pango/pangocairo.h>
 #include "gvgetfontlist.h"
 #ifdef HAVE_PANGO_FC_FONT_LOCK_FACE
+#include <ft2build.h>
+#include FT_FREETYPE_H
+#include <freetype/freetype.h>
 #include <pango/pangofc-font.h>
 #endif
 
