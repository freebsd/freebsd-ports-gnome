--- src/wp/ap/xp/ap_Dialog_Spell.cpp.orig	2016-04-15 15:54:03 UTC
+++ src/wp/ap/xp/ap_Dialog_Spell.cpp
@@ -251,7 +251,7 @@ bool AP_Dialog_Spell::nextMisspelledWord(void)
 					UT_return_val_if_fail (m_Suggestions, false);
 
 					// get suggestions from spelling engine
-					const UT_GenericVector<UT_UCSChar*> *cpvEngineSuggestions = nullptr;
+					const UT_GenericVector<UT_UCSChar*> *cpvEngineSuggestions = NULL;
 
 					if (checker->checkWord(m_pWord, m_iWordLength) == SpellChecker::LOOKUP_FAILED)
 					{
