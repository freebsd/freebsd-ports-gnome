--- cmake/CMakeModules/FindJsonCpp.cmake.orig	2019-03-14 03:58:28 UTC
+++ cmake/CMakeModules/FindJsonCpp.cmake
@@ -16,7 +16,7 @@ set(JSONCPP_FOUND "NO")
 set(OSSIM_HAS_JSONCPP 0)
 
 find_path( JSONCPP_INCLUDE_DIR json/json.h
-          PATHS /usr/include/jsoncpp )
+          PATHS ${CMAKE_INSTALL_PREFIX}/include/jsoncpp )
 
 find_library( JSONCPP_LIBRARY NAMES "jsoncpp")
 
