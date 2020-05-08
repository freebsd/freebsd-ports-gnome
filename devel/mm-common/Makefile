# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mm-common
PORTVERSION=	1.0.0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Common build infrastructure for the GNOME C++ binding libraries

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		meson pathfix python:3.5+ shebangfix tar:xz

SHEBANG_GLOB=	*.py
SHEBANG_FILES=	util/mm-common-get.in
BINARY_ALIAS=	python3=${PYTHON_CMD}

NO_ARCH=	yes

.include <bsd.port.mk>
