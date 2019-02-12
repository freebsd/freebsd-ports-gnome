--- src/canvas_helper.c.orig	2019-02-12 17:51:36 UTC
+++ src/canvas_helper.c
@@ -16,8 +16,10 @@
  * along with this program; if not, write to the Free Software
  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
  */
+
+#include <math.h>
+
 #include "main.h"
-#include "math.h"
 #include "canvas_helper.h"
 
 void convert_to_playfield (Theme *theme, PlayField * playfield, gint x, gint y,
