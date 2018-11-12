https://github.com/boostorg/asio/pull/135

--- boost/asio/detail/config.hpp.orig	2018-04-11 13:49:00 UTC
+++ boost/asio/detail/config.hpp
@@ -777,7 +777,7 @@
 #if !defined(BOOST_ASIO_HAS_STD_STRING_VIEW)
 # if !defined(BOOST_ASIO_DISABLE_STD_STRING_VIEW)
 #  if defined(__clang__)
-#   if (__cplusplus >= 201703)
+#   if defined(BOOST_ASIO_HAS_CLANG_LIBCXX) || (__cplusplus >= 201703)
 #    if __has_include(<string_view>)
 #     define BOOST_ASIO_HAS_STD_STRING_VIEW 1
 #    endif // __has_include(<string_view>)
