--- yc.el.orig	2018-06-04 13:46:33.083915000 +0900
+++ yc.el	2018-06-04 14:48:21.116298000 +0900
@@ -1736,6 +1736,7 @@
 				   (error nil))))
 	    (yc-eval-sexp (car expr)))))
       (setq files (cdr files)))
+    (message "")
     (if romkana-table
 	(setq yc-rH-conv-dic (yc-search-file-first-in-path
 			      romkana-table (list "." (getenv "HOME")
@@ -2071,7 +2072,7 @@
 ;; $BJ8@a$r;XDj$7$J$$>l9g!"8=:_$NJ8@a$,BP>]$H$J$k(B
 ;; $BFI$_$r<hF@$7$?J8@a$O$=$NFI$_$r%-%c%C%7%e$9$k(B
 ;; cut $B$,(B $BHs(Bnil $B$N>l9g!";XDjJ8@a0J9_$NFI$_$r:o=|$9$k(B
-(defun yc-yomi (&optional idx &optional cut)
+(defun yc-yomi (&optional idx cut)
   (if (integerp idx)
       (yc-put-bunsetsu-yomi idx (yc-get-bunsetsu-yomi idx cut) cut)
     (yc-put-bunsetsu-yomi yc-mark (yc-get-bunsetsu-yomi yc-mark cut) cut)))
