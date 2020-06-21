# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	glibmm
PORTVERSION=	2.64.2
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ interfaces for glib-2.0

LICENSE=	LGPL21

BUILD_DEPENDS=	mm-common-get:devel/mm-common \
		p5-XML-Parser>0:textproc/p5-XML-Parser \
		gm4:devel/m4

USES=		compiler:c++11-lang gettext gnome meson pathfix perl5 \
		pkgconfig python:3.5+,build shebangfix tar:xz
USE_GNOME=	glib20 libsigc++20
USE_LDCONFIG=	yes

SHEBANG_GLOB=	*.py
BINARY_ALIAS=	m4=${PREFIX}/bin/gm4

MESON_ARGS=	-Dbuild-documentation=false \
		-Dmaintainer-mode=true \
		-Dwarnings=max

PORTSCOUT?=	limitw:1,even
PLIST_SUB=	VERSION="2.4"

.include <bsd.port.mk>
