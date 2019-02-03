# $FreeBSD$

PORTNAME=	libhandy
PORTVERSION=	0.0.7
CATEGORIES=	x11-toolkits gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Widgets

LICENSE=	LGPL21

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libgladeui-2.so:devel/glade

USES=		gettext gnome meson pkgconfig uniquefiles
USE_GNOME=	cairo gtk30 introspection:build

USE_GITLAB=	yes
GL_SITE=	https://source.puri.sm/
GL_ACCOUNT=	Librem5
GL_COMMIT=	fac9fa59a83f47655d604796632a932d58cf60bb

MESON_ARGS=	-Dtests=false

# Fix conflicts with sysutils/coreutils
UNIQUE_SUFFIX=	-libhandy
UNIQUE_SUFFIX_FILES=    bin/example

.include <bsd.port.mk>
