# $FreeBSD$

PORTNAME=	libmanette
PORTVERSION=	0.2.1
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	...

LICENSE=	LGPL21

LIB_DEPENDS=	libgudev-1.0.so:devel/libgudev \
		libevdev.so:devel/libevdev

USES=		gnome meson tar:xz
USE_GNOME=	glib20 introspection:build

.include <bsd.port.mk>
