# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	muffin
PORTVERSION=	2.8.4
CATEGORIES=	x11-wm gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Compositing window manager forked from Mutter for use with Cinnamon

BUILD_DEPENDS=	zenity>=3.0.0:x11/zenity \
		gnome-autogen.sh:devel/gnome-common \
		gsettings-desktop-schemas>=3.4.0:devel/gsettings-desktop-schemas \
		gtkdoc-check:textproc/gtk-doc
LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification \
		libclutter-glx-1.0.so:graphics/clutter \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libcinnamon-desktop.so:x11/cinnamon-desktop
RUN_DEPENDS=	zenity>=3.0.0:x11/zenity

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

USES=		autoreconf:build execinfo gettext libtool gmake \
		pathfix pkgconfig python:2
USE_GNOME=	gconf2 gnomedocutils gnomeprefix gtk30 \
		intlhack introspection:build
USE_XORG=	x11 xext xrandr xcomposite xcursor xinerama ice sm
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -Wno-error=unused-function
CFLAGS+=	-I${LOCALBASE}/include -Wno-error=unused-function
LDFLAGS+=	-L${LOCALBASE}/lib
PATHFIX_MAKEFILEIN=	Makefile.am
CONFIGURE_ARGS=	--enable-compile-warnings=maximum
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.cinnamon.muffin.gschema.xml

pre-configure:
		@cd ${WRKSRC} && ${SETENV} NOCONFIGURE=yes ${SH} autogen.sh

post-patch:
	@${REINPLACE_CMD} -e 's|REQUIRED_AUTOMAKE_VERSION=1.10|REQUIRED_AUTOMAKE_VERSION=1.14|g' \
		${WRKSRC}/autogen.sh

.include <bsd.port.mk>
