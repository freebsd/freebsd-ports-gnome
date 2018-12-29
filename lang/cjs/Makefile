# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	cjs
PORTVERSION=	4.0.0
CATEGORIES=	lang gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	JavaScript bindings based on gobject-introspection

LICENSE=		MIT LGPL20+
LICENSE_COMB=		dual
LICENSE_FILE_LGPL20+ =	${WRKSRC}/COPYING.LGPL

BUILD_DEPENDS=	dbus>=0:devel/dbus
LIB_DEPENDS=	libffi.so:devel/libffi \
		libmozjs-52.so:lang/spidermonkey52

USES=		autoreconf compiler:c11 libtool gettext gmake gnome pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk30 introspection
USE_XORG=	x11 xext

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-profiler

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
