--- src/cpp/core/system/PosixSched.cpp.orig	2017-11-16 21:40:37 UTC
+++ src/cpp/core/system/PosixSched.cpp
@@ -15,7 +15,11 @@
 
 #include <core/system/PosixSched.hpp>
 
+#define _GNU_SOURCE
 #include <sched.h>
+#include <sys/types.h>
+#include <sys/param.h> // w/out this fails on i386 with error: use of undeclared identifier 'NBBY'
+#include <sys/cpuset.h>
 
 #include <core/Error.hpp>
 
@@ -41,9 +45,10 @@ bool isCpuAffinityEmpty(const CpuAffinit
 Error getCpuAffinity(CpuAffinity* pCpus)
 {
 #ifndef __APPLE__
-   cpu_set_t cs;
+/*
+   cpuset_t cs;
    CPU_ZERO(&cs);
-   if (::sched_getaffinity(0, sizeof(cs), &cs) == -1)
+   if (sched_getaffinity(0, sizeof(cs), &cs) == -1)
       return systemError(errno, ERROR_LOCATION);
 
    pCpus->clear();
@@ -55,7 +60,7 @@ Error getCpuAffinity(CpuAffinity* pCpus)
       else
          pCpus->push_back(false);
    }
-
+*/
    return Success();
 #else
    return systemError(boost::system::errc::not_supported, ERROR_LOCATION);
@@ -66,7 +71,8 @@ Error getCpuAffinity(CpuAffinity* pCpus)
 Error setCpuAffinity(const CpuAffinity& cpus)
 {
 #ifndef __APPLE__
-   cpu_set_t cs;
+/*
+   cpuset_t cs;
    CPU_ZERO(&cs);
 
    for (std::size_t i=0; i<cpus.size(); i++)
@@ -79,7 +85,7 @@ Error setCpuAffinity(const CpuAffinity& 
 
    if (::sched_setaffinity(0, sizeof(cs), &cs) == -1)
       return systemError(errno, ERROR_LOCATION);
-
+*/
    return Success();
 #else
    return systemError(boost::system::errc::not_supported, ERROR_LOCATION);
