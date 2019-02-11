Bump version, 500 is too low for use to expose gethostname()

--- src/x11/window-props.c.orig	2019-02-07 00:26:03 UTC
+++ src/x11/window-props.c
@@ -34,7 +34,7 @@
  * along with this program; if not, see <http://www.gnu.org/licenses/>.
  */
 
-#define _XOPEN_SOURCE 500 /* for gethostname() */
+#define _XOPEN_SOURCE 600 /* for gethostname() */
 
 #include "config.h"
 
