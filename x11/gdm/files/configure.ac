--- configure.ac.orig	2015-08-16 21:52:30.000000000 +0200
+++ configure.ac	2015-08-16 21:58:19.000000000 +0200
@@ -245,6 +245,15 @@
             with_tcp_wrappers=auto)
 
 
+AC_ARG_WITH(console-kit,
+            AS_HELP_STRING([--with-console-kit],
+                           [Add ConsoleKit support @<:@default=auto@:>@]),,
+            with_console_kit=no)
+
+AC_ARG_WITH(systemd,
+            AS_HELP_STRING([--with-systemd],
+                           [Add systemd support @<:@default=auto@:>@]),
+            [with_systemd=$withval], [with_systemd=auto])
 AC_ARG_WITH([systemdsystemunitdir],
             AS_HELP_STRING([--with-systemdsystemunitdir=DIR],
                            [Directory for systemd service files]),
@@ -870,12 +879,42 @@
 CPPFLAGS="$xinerama_save_cppflags"
 
 dnl ---------------------------------------------------------------------------
+dnl - Check for ConsoleKit support
+dnl ---------------------------------------------------------------------------
+
+use_console_kit=no
+if test "x$with_console_kit" != "xno" ; then
+	use_console_kit=yes
+	AC_DEFINE(WITH_CONSOLE_KIT, 1, [Define to enable ConsoleKit support])
+fi
+AM_CONDITIONAL(WITH_CONSOLE_KIT, test x$use_console_kit = xyes)
+AC_SUBST(WITH_CONSOLE_KIT)
+
+dnl ---------------------------------------------------------------------------
 dnl - Check for systemd support
 dnl ---------------------------------------------------------------------------
 
 PKG_CHECK_MODULES(SYSTEMD,
-                  [libsystemd])
+                  [libsystemd-login >= 186 libsystemd-daemon],
+                  [have_systemd=yes], [have_systemd=no])
+
+if test "x$with_systemd" = "xauto" ; then
+        if test x$have_systemd = xno ; then
+                use_systemd=no
+        else
+                use_systemd=yes
+        fi
+else
+        use_systemd="$with_systemd"
+fi
+
+if test "x$use_systemd" != "xno" ; then
+        if test "x$have_systemd" = "xno"; then
+                AC_MSG_ERROR([Systemd support explicitly required, but systemd not found])
+        fi
 
+        AC_DEFINE(WITH_SYSTEMD, 1, [Define to enable systemd support])
+fi
 AC_SUBST(SYSTEMD_CFLAGS)
 AC_SUBST(SYSTEMD_LIBS)
 
@@ -1068,6 +1107,14 @@
 AC_SUBST(GDM_CUSTOM_CONF)
 AC_SUBST(GDM_OLD_CONF, '${gdmconfdir}/gdm.conf')
 
+AC_ARG_WITH(consolekit-directory,
+              [AC_HELP_STRING([--with-consolekit-directory],
+                              [Specify the directory of ck-get-x11-display-device @<:@default=libexecdir@:>@])],,
+                              [with_consolekit_directory="\${libexecdir}"])
+
+CONSOLEKIT_DIR=$with_consolekit_directory
+AC_SUBST(CONSOLEKIT_DIR)
+
 AC_ARG_WITH(gnome-settings-daemon-directory,
               [AC_HELP_STRING([--with-gnome-settings-daemon-directory],
                               [Specify the directory of gnome-settings-daemon used by the chooser @<:@default=libexecdir@:>@])],,
@@ -1549,6 +1596,7 @@
         dmconfdir:                ${dmconfdir}
         localstatedir:            ${localstatedir}
         datadir:                  ${datadir}
+        consolekit location:      ${with_consolekit_directory}
 	gnome-settings-daemon location: ${with_gnome_settings_daemon_directory}
 	gnome-session-check-accel location: ${with_check_accelerated_directory}
 	source code location:	  ${srcdir}
@@ -1578,6 +1626,8 @@
 "        Xinerama support:         ${XINERAMA_SUPPORT}
         XDMCP support:            ${XDMCP_SUPPORT}
         SELinux support:          ${use_selinux}
+        ConsoleKit support:       ${use_console_kit}
+        systemd support:          ${use_systemd}
         systemd unit dir:         ${with_systemdsystemunitdir}
         plymouth support:         ${use_plymouth}
         wayland support:          ${use_wayland}
