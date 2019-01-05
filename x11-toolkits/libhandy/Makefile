# $FreeBSD$

PORTNAME=	libhandy
PORTVERSION=	0.0.6
CATEGORIES=	x11-toolkits gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Widgets

LICENSE=	LGPL21

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libgladeui-2.so:devel/glade

USES=		gettext gnome meson
USE_GNOME=	cairo gtk30 introspection:build

USE_GITLAB=	yes
GL_SITE=	https://source.puri.sm/
GL_ACCOUNT=	Librem5
GL_COMMIT=	cfb1326f11472b77596e136c81424d5ae542e536

MESON_ARGS=	-Dtests=false

# Fix conflicts with sysutils/coreutils
UNIQUE_SUFFIX=	-libhandy
UNIQUE_SUFFIX_FILES=    bin/example

.include <bsd.port.mk>
