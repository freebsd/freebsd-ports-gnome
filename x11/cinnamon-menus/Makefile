# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	cinnamon-menus
PORTVERSION=	2.8.0
CATEGORIES=	x11 gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Additional UI API for cinnamon

BUILD_DEPENDS=	xkeyboard-config>=0:x11/xkeyboard-config \
		gnome-common>=0:devel/gnome-common \
		libxkbfile>=0:x11/libxkbfile
RUN_DEPENDS=	xkeyboard-config>=0:x11/xkeyboard-config \
		libxkbfile>=0:x11/libxkbfile

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

USES=		autoreconf gettext gmake libtool pathfix pkgconfig \
		python:2 tar:xz
USE_GNOME=	gnomemenus3 gnomeprefix gtk30 introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
