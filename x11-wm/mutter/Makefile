# Created by: Pawel Worach <pawel.worach@gmail.com>
# $FreeBSD$

PORTNAME=	mutter
PORTVERSION=	3.31.2
CATEGORIES=	x11-wm gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Window and compositing manager based on Clutter

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	zenity>=3.0.0:x11/zenity \
		xkeyboard-config>=0:x11/xkeyboard-config \
		evdev-proto>=0:devel/evdev-proto \
		gsettings-desktop-schemas>=3.4.0:devel/gsettings-desktop-schemas \
		gnome-settings-daemon>=3.28:sysutils/gnome-settings-daemon
LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification \
		libfribidi.so:converters/fribidi \
		libxkbcommon.so:x11/libxkbcommon \
		libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libupower-glib.so:sysutils/upower \
		libjson-glib-1.0.so:devel/json-glib \
		libxkbfile.so:x11/libxkbfile \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libdrm.so:graphics/libdrm
RUN_DEPENDS=	zenity>=3.0.0:x11/zenity \
		xkeyboard-config>=0:x11/xkeyboard-config \
		gsettings-desktop-schemas>=3.4.0:devel/gsettings-desktop-schemas \
		gnome-settings-daemon>=3.28:sysutils/gnome-settings-daemon

TEST_DEPENDS=	bash:shell/bash

PORTSCOUT=	limitw:1,even

USES=		compiler:c++0x gettext gl gnome localbase meson \
		pkgconfig python:3.5+,build shebangfix tar:xz
USE_GL=		egl
USE_GNOME=	cairo gdkpixbuf2 gnomedesktop3 introspection
USE_XORG=	ice sm x11 xcb xcomposite xcursor xdamage xext xfixes \
		xi xinerama xrandr xrender xtst
USE_LDCONFIG=	yes
#CFLAGS+=	-Wno-unknown-warning-option \
#		-Wno-format-nonliteral
#CPPFLAGS+=	-fno-omit-frame-pointer
#CONFIGURE_ARGS=	--without-libwacom \
#		--disable-wayland

# udev support when using the X11 backend
MESON_ARGS+=	-Dudev=false

#needs systemd
MESON_ARGS+=	-Dnative_backend=false

# needs pipewire
MESON_ARGS+=	-Dremote_desktop=false

# Wayland deps:
# Xwayland??? this seems wrong, disable and still require
BUILD_DEPENDS=	Xwayland:x11-servers/xwayland
MESON_ARGS+=	-Dwayland=false \
		-Dtests=false

# make option?
LIB_DEPENDS+=	libwacom.so:x11/libwacom

# Required by embedded cogl/clutter forks.
#CONFIGURE_ARGS+=	--with-x \
#		--with-gl-libname=libGL.so \
#		--with-gles1-libname=libGLESv1_CM \
#		--with-gles2-libname=libGLESv2 \
#		--enable-kms-egl-platform=yes \
#		--enable-xlib-egl-platform=yes \
#		--disable-wayland-egl-server \
#		--enable-compile-warnings=yes

GLIB_SCHEMAS=	org.gnome.mutter.gschema.xml \
		org.gnome.mutter.wayland.gschema.xml

SHEBANG_FILES=	clutter/tests/interactive/meson/gen-test-unit-names.sh \
		cogl/tests/conform/meson/find-conform-unit-tests.sh \
		cogl/tests/unit/meson/find-unit-tests.sh \
		src/backends/native/gen-default-modes.py

.include <bsd.port.mk>
