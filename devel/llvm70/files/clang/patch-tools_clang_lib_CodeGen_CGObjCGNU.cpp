--- tools/clang/lib/CodeGen/CGObjCGNU.cpp.orig	2018-12-28 16:37:45 UTC
+++ tools/clang/lib/CodeGen/CGObjCGNU.cpp
@@ -277,6 +277,8 @@ protected:
     Fields.addInt(Int8Ty, 0);
   }
 
+  virtual llvm::Constant *GenerateCategoryProtocolList(const
+      ObjCCategoryDecl *OCD);
   virtual ConstantArrayBuilder PushPropertyListHeader(ConstantStructBuilder &Fields,
       int count) {
       // int count;
@@ -1164,6 +1166,15 @@ class CGObjCGNUstep2 : public CGObjCGNUs
     return MethodList.finishAndCreateGlobal(".objc_protocol_method_list",
                                             CGM.getPointerAlign());
   }
+  llvm::Constant *GenerateCategoryProtocolList(const ObjCCategoryDecl *OCD)
+    override {
+    SmallVector<llvm::Constant*, 16> Protocols;
+    for (const auto *PI : OCD->getReferencedProtocols())
+      Protocols.push_back(
+          llvm::ConstantExpr::getBitCast(GenerateProtocolRef(PI),
+            ProtocolPtrTy));
+    return GenerateProtocolList(Protocols);
+  }
 
   llvm::Value *LookupIMPSuper(CodeGenFunction &CGF, Address ObjCSuper,
                               llvm::Value *cmd, MessageSendInfo &MSI) override {
@@ -1547,7 +1558,7 @@ class CGObjCGNUstep2 : public CGObjCGNUs
             sectionName<CategorySection>());
       if (!EmittedClass) {
         createNullGlobal(".objc_null_cls_init_ref", NULLPtr,
-            sectionName<ClassReferenceSection>());
+            sectionName<ClassSection>());
         createNullGlobal(".objc_null_class_ref", { NULLPtr, NULLPtr },
             sectionName<ClassReferenceSection>());
       }
@@ -3099,18 +3110,21 @@ llvm::Constant *CGObjCGNU::MakeBitField(
   return ptr;
 }
 
+llvm::Constant *CGObjCGNU::GenerateCategoryProtocolList(const
+    ObjCCategoryDecl *OCD) {
+  SmallVector<std::string, 16> Protocols;
+  for (const auto *PD : OCD->getReferencedProtocols())
+    Protocols.push_back(PD->getNameAsString());
+  return GenerateProtocolList(Protocols);
+}
+
 void CGObjCGNU::GenerateCategory(const ObjCCategoryImplDecl *OCD) {
   const ObjCInterfaceDecl *Class = OCD->getClassInterface();
   std::string ClassName = Class->getNameAsString();
   std::string CategoryName = OCD->getNameAsString();
 
   // Collect the names of referenced protocols
-  SmallVector<std::string, 16> Protocols;
   const ObjCCategoryDecl *CatDecl = OCD->getCategoryDecl();
-  const ObjCList<ObjCProtocolDecl> &Protos = CatDecl->getReferencedProtocols();
-  for (ObjCList<ObjCProtocolDecl>::iterator I = Protos.begin(),
-       E = Protos.end(); I != E; ++I)
-    Protocols.push_back((*I)->getNameAsString());
 
   ConstantInitBuilder Builder(CGM);
   auto Elements = Builder.beginStruct();
@@ -3132,7 +3146,7 @@ void CGObjCGNU::GenerateCategory(const O
           GenerateMethodList(ClassName, CategoryName, ClassMethods, true),
           PtrTy);
   // Protocol list
-  Elements.addBitCast(GenerateProtocolList(Protocols), PtrTy);
+  Elements.addBitCast(GenerateCategoryProtocolList(CatDecl), PtrTy);
   if (isRuntime(ObjCRuntime::GNUstep, 2)) {
     const ObjCCategoryDecl *Category =
       Class->FindCategoryDeclaration(OCD->getIdentifier());
