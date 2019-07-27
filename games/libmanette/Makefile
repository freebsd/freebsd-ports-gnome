# $FreeBSD$

PORTNAME=	libmanette
PORTVERSION=	0.2.2
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Simple GObject game controller library.

LICENSE=	LGPL21

BUILD_DEPENDS=	valac:lang/vala \
		evdev-proto>=0:devel/evdev-proto
LIB_DEPENDS=	libgudev-1.0.so:devel/libgudev \
		libevdev.so:devel/libevdev

USES=		gnome meson pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build

.include <bsd.port.mk>
