--- theonionbox/theonionbox.py.orig	2018-05-27 22:03:29 UTC
+++ theonionbox/theonionbox.py
@@ -505,17 +505,17 @@ required_modules = {
     },
     'apscheduler2': {
         'module': 'apscheduler',
-        'version': '>=2.1.2, <3.*; python_version<"3.0"'
+        'version': '>=3.4'
     },
     'apscheduler3': {
         'module': 'apscheduler',
-        'version': '>=3.4; python_version>="3.0"'
+        'version': '>=3.4'
     },
     'requests': {
         'version': '>=2.18.0'
     },
     'tzlocal': {
-        'version': '>=1.5'
+        'version': '>=1.4'
     },
     'pysocks': {
         'version': '>=1.6.7'
