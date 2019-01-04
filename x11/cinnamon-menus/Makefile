# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	cinnamon-menus
PORTVERSION=	4.0.0
CATEGORIES=	x11 gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Additional UI API for cinnamon

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	gnome-autogen.sh:devel/gnome-common \
		xkeyboard-config>=0:x11/xkeyboard-config
RUN_DEPENDS=	xkeyboard-config>=0:x11/xkeyboard-config

USES=		autoreconf gettext-runtime gmake gnome libtool pathfix pkgconfig

USE_GNOME=	gtk30 intltool introspection:build

USE_XORG=	xkbfile

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
