# Created by: Yukihiro Nakai <nakai@FreeBSD.org>
# $FreeBSD$

PORTNAME=	atomix
PORTVERSION=	3.32.1
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Yet another little mind game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	appstream-util:devel/appstream-glib
LIB_DEPENDS=	libgnome-games-support-1.so:games/libgnome-games-support

USES=		gettext gnome localbase meson pkgconfig python:3.5+,build tar:xz
USE_GNOME=	cairo gdkpixbuf2 gtk30 intlhack

PORTSCOUT=	limitw:1,even
BINARY_ALIAS=	python3=${PYTHON_VERSION}

.include <bsd.port.mk>
