--- Telegram/SourceFiles/ui/widgets/labels.cpp.orig	2018-08-04 18:53:40 UTC
+++ Telegram/SourceFiles/ui/widgets/labels.cpp
@@ -364,11 +364,11 @@ Text::StateResult FlatLabel::dragActionF
 		}
 	}
 
-#if defined Q_OS_LINUX32 || defined Q_OS_LINUX64
+#if defined Q_OS_LINUX32 || defined Q_OS_LINUX64 || defined Q_OS_FREEBSD
 	if (!_selection.empty()) {
 		QApplication::clipboard()->setText(_text.originalText(_selection, _contextExpandLinksMode), QClipboard::Selection);
 	}
-#endif // Q_OS_LINUX32 || Q_OS_LINUX64
+#endif // Q_OS_LINUX32 || Q_OS_LINUX64 || Q_OS_FREEBSD
 
 	return state;
 }
