# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-font-viewer
PORTVERSION=	3.32.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME font viewer utility

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libharfbuzz.so:print/harfbuzz

USES=		compiler:c11 gettext gnome meson pkgconfig tar:xz
USE_GNOME=	cairo gdkpixbuf2 gtk30 gnomedesktop3
USE_LDCONFIG=	yes

PORTSCOUT=	limitw:1,even
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
