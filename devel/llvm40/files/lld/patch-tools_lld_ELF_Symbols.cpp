--- tools/lld/ELF/Symbols.cpp.orig	2017-02-01 22:45:57 UTC
+++ tools/lld/ELF/Symbols.cpp
@@ -343,45 +343,45 @@ template bool SymbolBody::hasThunk<ELF32BE>() const;
 template bool SymbolBody::hasThunk<ELF64LE>() const;
 template bool SymbolBody::hasThunk<ELF64BE>() const;
 
-template uint32_t SymbolBody::template getVA<ELF32LE>(uint32_t) const;
-template uint32_t SymbolBody::template getVA<ELF32BE>(uint32_t) const;
-template uint64_t SymbolBody::template getVA<ELF64LE>(uint64_t) const;
-template uint64_t SymbolBody::template getVA<ELF64BE>(uint64_t) const;
+template uint32_t SymbolBody::getVA<ELF32LE>(uint32_t) const;
+template uint32_t SymbolBody::getVA<ELF32BE>(uint32_t) const;
+template uint64_t SymbolBody::getVA<ELF64LE>(uint64_t) const;
+template uint64_t SymbolBody::getVA<ELF64BE>(uint64_t) const;
 
-template uint32_t SymbolBody::template getGotVA<ELF32LE>() const;
-template uint32_t SymbolBody::template getGotVA<ELF32BE>() const;
-template uint64_t SymbolBody::template getGotVA<ELF64LE>() const;
-template uint64_t SymbolBody::template getGotVA<ELF64BE>() const;
+template uint32_t SymbolBody::getGotVA<ELF32LE>() const;
+template uint32_t SymbolBody::getGotVA<ELF32BE>() const;
+template uint64_t SymbolBody::getGotVA<ELF64LE>() const;
+template uint64_t SymbolBody::getGotVA<ELF64BE>() const;
 
-template uint32_t SymbolBody::template getGotOffset<ELF32LE>() const;
-template uint32_t SymbolBody::template getGotOffset<ELF32BE>() const;
-template uint64_t SymbolBody::template getGotOffset<ELF64LE>() const;
-template uint64_t SymbolBody::template getGotOffset<ELF64BE>() const;
+template uint32_t SymbolBody::getGotOffset<ELF32LE>() const;
+template uint32_t SymbolBody::getGotOffset<ELF32BE>() const;
+template uint64_t SymbolBody::getGotOffset<ELF64LE>() const;
+template uint64_t SymbolBody::getGotOffset<ELF64BE>() const;
 
-template uint32_t SymbolBody::template getGotPltVA<ELF32LE>() const;
-template uint32_t SymbolBody::template getGotPltVA<ELF32BE>() const;
-template uint64_t SymbolBody::template getGotPltVA<ELF64LE>() const;
-template uint64_t SymbolBody::template getGotPltVA<ELF64BE>() const;
+template uint32_t SymbolBody::getGotPltVA<ELF32LE>() const;
+template uint32_t SymbolBody::getGotPltVA<ELF32BE>() const;
+template uint64_t SymbolBody::getGotPltVA<ELF64LE>() const;
+template uint64_t SymbolBody::getGotPltVA<ELF64BE>() const;
 
-template uint32_t SymbolBody::template getThunkVA<ELF32LE>() const;
-template uint32_t SymbolBody::template getThunkVA<ELF32BE>() const;
-template uint64_t SymbolBody::template getThunkVA<ELF64LE>() const;
-template uint64_t SymbolBody::template getThunkVA<ELF64BE>() const;
+template uint32_t SymbolBody::getThunkVA<ELF32LE>() const;
+template uint32_t SymbolBody::getThunkVA<ELF32BE>() const;
+template uint64_t SymbolBody::getThunkVA<ELF64LE>() const;
+template uint64_t SymbolBody::getThunkVA<ELF64BE>() const;
 
-template uint32_t SymbolBody::template getGotPltOffset<ELF32LE>() const;
-template uint32_t SymbolBody::template getGotPltOffset<ELF32BE>() const;
-template uint64_t SymbolBody::template getGotPltOffset<ELF64LE>() const;
-template uint64_t SymbolBody::template getGotPltOffset<ELF64BE>() const;
+template uint32_t SymbolBody::getGotPltOffset<ELF32LE>() const;
+template uint32_t SymbolBody::getGotPltOffset<ELF32BE>() const;
+template uint64_t SymbolBody::getGotPltOffset<ELF64LE>() const;
+template uint64_t SymbolBody::getGotPltOffset<ELF64BE>() const;
 
-template uint32_t SymbolBody::template getPltVA<ELF32LE>() const;
-template uint32_t SymbolBody::template getPltVA<ELF32BE>() const;
-template uint64_t SymbolBody::template getPltVA<ELF64LE>() const;
-template uint64_t SymbolBody::template getPltVA<ELF64BE>() const;
+template uint32_t SymbolBody::getPltVA<ELF32LE>() const;
+template uint32_t SymbolBody::getPltVA<ELF32BE>() const;
+template uint64_t SymbolBody::getPltVA<ELF64LE>() const;
+template uint64_t SymbolBody::getPltVA<ELF64BE>() const;
 
-template uint32_t SymbolBody::template getSize<ELF32LE>() const;
-template uint32_t SymbolBody::template getSize<ELF32BE>() const;
-template uint64_t SymbolBody::template getSize<ELF64LE>() const;
-template uint64_t SymbolBody::template getSize<ELF64BE>() const;
+template uint32_t SymbolBody::getSize<ELF32LE>() const;
+template uint32_t SymbolBody::getSize<ELF32BE>() const;
+template uint64_t SymbolBody::getSize<ELF64LE>() const;
+template uint64_t SymbolBody::getSize<ELF64BE>() const;
 
 template class elf::Undefined<ELF32LE>;
 template class elf::Undefined<ELF32BE>;
