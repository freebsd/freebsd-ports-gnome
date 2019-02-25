# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	geoclue
PORTVERSION=	2.5.2
CATEGORIES=	net devel gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	D-Bus service that provides location information

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	valac:lang/vala \
		gtkdoc-scan:textproc/gtk-doc
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libsoup-2.4.so:devel/libsoup

USES=		gettext gnome localbase meson pkgconfig python:3.5+,build tar:xz
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes
MESON_ARGS=	-D3g-source=false \
		-Dcdma-source=false \
		-Dmodem-gps-source=false \
		-Dnmea-source=false \
		-Ddemo-agent=false

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_COMMIT=	ed2d81fe558b657b52940dd52316bcc1a32d0cff

BINARY_ALIAS=	python3=${PYTHON_VERSION}

post-install:
	@cd ${STAGEDIR}${PREFIX}/etc/geoclue && \
		${MV} geoclue.conf geoclue.conf.sample

.include <bsd.port.mk>
