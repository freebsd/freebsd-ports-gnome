https://github.com/mate-desktop/mate-utils/commit/a3c64fdcbb6b16bfae2e9b1fa8df9126f2fbeb1e

--- mate-dictionary/libgdict/gdict-client-context.h.orig	2017-06-23 13:24:20 UTC
+++ mate-dictionary/libgdict/gdict-client-context.h
@@ -20,7 +20,7 @@
 #ifndef __GDICT_CLIENT_CONTEXT_H__
 #define __GDICT_CLIENT_CONTEXT_H__
 
-#include <glib-object.h>
+#include "gdict-context.h"
 
 #define GDICT_TYPE_CLIENT_CONTEXT		(gdict_client_context_get_type ())
 #define GDICT_CLIENT_CONTEXT(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), GDICT_TYPE_CLIENT_CONTEXT, GdictClientContext))
