# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	cjs
PORTVERSION=	4.6.0
CATEGORIES=	lang gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	JavaScript bindings based on gobject-introspection

LICENSE=		MIT LGPL20+
LICENSE_COMB=		dual
LICENSE_FILE_MIT=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL20+ =	${WRKSRC}/COPYING.LGPL

BUILD_DEPENDS=	gnome-autogen.sh:devel/gnome-common
LIB_DEPENDS=	libffi.so:devel/libffi \
		libharfbuzz.so:print/harfbuzz \
		libmozjs-52.so:lang/spidermonkey52

USES=		autoreconf compiler:c11 gettext libtool gmake gnome pathfix pkgconfig xorg
USE_GNOME=	cairo gdkpixbuf2 gtk30 introspection
USE_XORG=	x11 xext

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-profiler

INSTALL_TARGET=	install-strip

PORTSCOUT=	limit:^[0-9.]+$$	# ignore master.mint* tags

.include <bsd.port.mk>
