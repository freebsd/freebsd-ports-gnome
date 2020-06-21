# $FreeBSD$

PORTNAME=	libdazzle
DISTVERSION=	3.36.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Companion library to GObject and Gtk+

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala

USES=		compiler:c11 gnome meson pkgconfig tar:xz
USE_GNOME=	gtk30 introspection:build

USE_LDCONFIG=	yes
MESON_ARGS=	-Denable_tests=false

PORTSCOUT=	limitw:1,even

.include <bsd.port.mk>
