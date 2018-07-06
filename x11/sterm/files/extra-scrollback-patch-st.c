--- st.c.orig	2018-03-20 20:29:59 UTC
+++ st.c
@@ -121,6 +121,9 @@ typedef struct {
 	int col;      /* nb col */
 	Line *line;   /* screen */
 	Line *alt;    /* alternate screen */
+	Line hist[HISTSIZE]; /* history buffer */
+	int histi;    /* history index */
+	int scr;      /* scroll back */
 	int *dirty;   /* dirtyness of lines */
 	TCursor c;    /* cursor */
 	int ocx;      /* old cursor col */
@@ -188,8 +191,8 @@ static void tnewline(int);
 static void tputtab(int);
 static void tputc(Rune);
 static void treset(void);
-static void tscrollup(int, int);
-static void tscrolldown(int, int);
+static void tscrollup(int, int, int);
+static void tscrolldown(int, int, int);
 static void tsetattr(int *, int);
 static void tsetchar(Rune, Glyph *, int, int);
 static void tsetdirt(int, int);
@@ -431,10 +434,10 @@ tlinelen(int y)
 {
 	int i = term.col;
 
-	if (term.line[y][i - 1].mode & ATTR_WRAP)
+	if (TLINE(y)[i - 1].mode & ATTR_WRAP)
 		return i;
 
-	while (i > 0 && term.line[y][i - 1].u == ' ')
+	while (i > 0 && TLINE(y)[i - 1].u == ' ')
 		--i;
 
 	return i;
@@ -543,7 +546,7 @@ selsnap(int *x, int *y, int direction)
 		 * Snap around if the word wraps around at the end or
 		 * beginning of a line.
 		 */
-		prevgp = &term.line[*y][*x];
+		prevgp = &TLINE(*y)[*x];
 		prevdelim = ISDELIM(prevgp->u);
 		for (;;) {
 			newx = *x + direction;
@@ -558,14 +561,14 @@ selsnap(int *x, int *y, int direction)
 					yt = *y, xt = *x;
 				else
 					yt = newy, xt = newx;
-				if (!(term.line[yt][xt].mode & ATTR_WRAP))
+				if (!(TLINE(yt)[xt].mode & ATTR_WRAP))
 					break;
 			}
 
 			if (newx >= tlinelen(newy))
 				break;
 
-			gp = &term.line[newy][newx];
+			gp = &TLINE(newy)[newx];
 			delim = ISDELIM(gp->u);
 			if (!(gp->mode & ATTR_WDUMMY) && (delim != prevdelim
 					|| (delim && gp->u != prevgp->u)))
@@ -586,14 +589,14 @@ selsnap(int *x, int *y, int direction)
 		*x = (direction < 0) ? 0 : term.col - 1;
 		if (direction < 0) {
 			for (; *y > 0; *y += direction) {
-				if (!(term.line[*y-1][term.col-1].mode
+				if (!(TLINE(*y-1)[term.col-1].mode
 						& ATTR_WRAP)) {
 					break;
 				}
 			}
 		} else if (direction > 0) {
 			for (; *y < term.row-1; *y += direction) {
-				if (!(term.line[*y][term.col-1].mode
+				if (!(TLINE(*y)[term.col-1].mode
 						& ATTR_WRAP)) {
 					break;
 				}
@@ -624,13 +627,13 @@ getsel(void)
 		}
 
 		if (sel.type == SEL_RECTANGULAR) {
-			gp = &term.line[y][sel.nb.x];
+			gp = &TLINE(y)[sel.nb.x];
 			lastx = sel.ne.x;
 		} else {
-			gp = &term.line[y][sel.nb.y == y ? sel.nb.x : 0];
+			gp = &TLINE(y)[sel.nb.y == y ? sel.nb.x : 0];
 			lastx = (sel.ne.y == y) ? sel.ne.x : term.col-1;
 		}
-		last = &term.line[y][MIN(lastx, linelen-1)];
+		last = &TLINE(y)[MIN(lastx, linelen-1)];
 		while (last >= gp && last->u == ' ')
 			--last;
 
@@ -835,6 +838,9 @@ ttyread(void)
 	if (buflen > 0)
 		memmove(buf, buf + written, buflen);
 
+	if (term.scr > 0 && term.scr < HISTSIZE-1)
+		term.scr++;
+
 	return ret;
 }
 
@@ -842,6 +848,9 @@ void
 ttywrite(const char *s, size_t n, int may_echo)
 {
 	const char *next;
+	Arg arg = (Arg) { .i = term.scr };
+
+	kscrolldown(&arg);
 
 	if (may_echo && IS_SET(MODE_ECHO))
 		twrite(s, n, 1);
@@ -1053,13 +1062,54 @@ tswapscreen(void)
 }
 
 void
-tscrolldown(int orig, int n)
+kscrolldown(const Arg* a)
+{
+	int n = a->i;
+
+	if (n < 0)
+		n = term.row + n;
+
+	if (n > term.scr)
+		n = term.scr;
+
+	if (term.scr > 0) {
+		term.scr -= n;
+		selscroll(0, -n);
+		tfulldirt();
+	}
+}
+
+void
+kscrollup(const Arg* a)
+{
+	int n = a->i;
+
+	if (n < 0)
+		n = term.row + n;
+
+	if (term.scr <= HISTSIZE-n) {
+		term.scr += n;
+		selscroll(0, n);
+		tfulldirt();
+	}
+}
+
+
+void
+tscrolldown(int orig, int n, int copyhist)
 {
 	int i;
 	Line temp;
 
 	LIMIT(n, 0, term.bot-orig+1);
 
+	if (copyhist) {
+		term.histi = (term.histi - 1 + HISTSIZE) % HISTSIZE;
+		temp = term.hist[term.histi];
+		term.hist[term.histi] = term.line[term.bot];
+		term.line[term.bot] = temp;
+	}
+
 	tsetdirt(orig, term.bot-n);
 	tclearregion(0, term.bot-n+1, term.col-1, term.bot);
 
@@ -1073,13 +1123,20 @@ tscrolldown(int orig, int n)
 }
 
 void
-tscrollup(int orig, int n)
+tscrollup(int orig, int n, int copyhist)
 {
 	int i;
 	Line temp;
 
 	LIMIT(n, 0, term.bot-orig+1);
 
+	if (copyhist) {
+		term.histi = (term.histi + 1) % HISTSIZE;
+		temp = term.hist[term.histi];
+		term.hist[term.histi] = term.line[orig];
+		term.line[orig] = temp;
+	}
+
 	tclearregion(0, orig, term.col-1, orig+n-1);
 	tsetdirt(orig+n, term.bot);
 
@@ -1128,7 +1185,7 @@ tnewline(int first_col)
 	int y = term.c.y;
 
 	if (y == term.bot) {
-		tscrollup(term.top, 1);
+		tscrollup(term.top, 1, 1);
 	} else {
 		y++;
 	}
@@ -1293,14 +1350,14 @@ void
 tinsertblankline(int n)
 {
 	if (BETWEEN(term.c.y, term.top, term.bot))
-		tscrolldown(term.c.y, n);
+		tscrolldown(term.c.y, n, 0);
 }
 
 void
 tdeleteline(int n)
 {
 	if (BETWEEN(term.c.y, term.top, term.bot))
-		tscrollup(term.c.y, n);
+		tscrollup(term.c.y, n, 0);
 }
 
 int32_t
@@ -1729,11 +1786,11 @@ csihandle(void)
 		break;
 	case 'S': /* SU -- Scroll <n> line up */
 		DEFAULT(csiescseq.arg[0], 1);
-		tscrollup(term.top, csiescseq.arg[0]);
+		tscrollup(term.top, csiescseq.arg[0], 0);
 		break;
 	case 'T': /* SD -- Scroll <n> line down */
 		DEFAULT(csiescseq.arg[0], 1);
-		tscrolldown(term.top, csiescseq.arg[0]);
+		tscrolldown(term.top, csiescseq.arg[0], 0);
 		break;
 	case 'L': /* IL -- Insert <n> blank lines */
 		DEFAULT(csiescseq.arg[0], 1);
@@ -2257,7 +2314,7 @@ eschandle(uchar ascii)
 		return 0;
 	case 'D': /* IND -- Linefeed */
 		if (term.c.y == term.bot) {
-			tscrollup(term.top, 1);
+			tscrollup(term.top, 1, 1);
 		} else {
 			tmoveto(term.c.x, term.c.y+1);
 		}
@@ -2270,7 +2327,7 @@ eschandle(uchar ascii)
 		break;
 	case 'M': /* RI -- Reverse index */
 		if (term.c.y == term.top) {
-			tscrolldown(term.top, 1);
+			tscrolldown(term.top, 1, 1);
 		} else {
 			tmoveto(term.c.x, term.c.y-1);
 		}
@@ -2489,7 +2546,7 @@ twrite(const char *buf, int buflen, int 
 void
 tresize(int col, int row)
 {
-	int i;
+	int i, j;
 	int minrow = MIN(row, term.row);
 	int mincol = MIN(col, term.col);
 	int *bp;
@@ -2526,7 +2583,15 @@ tresize(int col, int row)
 	term.dirty = xrealloc(term.dirty, row * sizeof(*term.dirty));
 	term.tabs = xrealloc(term.tabs, col * sizeof(*term.tabs));
 
-	/* resize each row to new width, zero-pad if needed */
+	for (i = 0; i < HISTSIZE; i++) {
+		term.hist[i] = xrealloc(term.hist[i], col * sizeof(Glyph));
+		for (j = mincol; j < col; j++) {
+			term.hist[i][j] = term.c.attr;
+			term.hist[i][j].u = ' ';
+		}
+	}
+
+	/* resize each r w to new width, zero-pad if needed */
 	for (i = 0; i < minrow; i++) {
 		term.line[i] = xrealloc(term.line[i], col * sizeof(Glyph));
 		term.alt[i]  = xrealloc(term.alt[i],  col * sizeof(Glyph));
@@ -2583,7 +2648,7 @@ drawregion(int x1, int y1, int x2, int y
 			continue;
 
 		term.dirty[y] = 0;
-		xdrawline(term.line[y], x1, y, x2);
+		xdrawline(TLINE(y), x1, y, x2);
 	}
 }
 
@@ -2604,8 +2669,10 @@ draw(void)
 		cx--;
 
 	drawregion(0, 0, term.col, term.row);
-	xdrawcursor(cx, term.c.y, term.line[term.c.y][cx],
-			term.ocx, term.ocy, term.line[term.ocy][term.ocx]);
+	if (term.scr == 0) {
+		xdrawcursor(cx, term.c.y, term.line[term.c.y][cx],
+				term.ocx, term.ocy, term.line[term.ocy][term.ocx]);
+	}
 	term.ocx = cx, term.ocy = term.c.y;
 	xfinishdraw();
 }
