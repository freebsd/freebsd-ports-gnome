# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libsoup
PORTVERSION=	2.70.0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	SOAP (Simple Object Access Protocol) implementation in C

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	glib-networking>=2.29.18:net/glib-networking \
		gtkdoc-scan:textproc/gtk-doc
LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libbrotlidec.so:archivers/brotli \
		libpsl.so:dns/libpsl
RUN_DEPENDS=	glib-networking>=2.29.18:net/glib-networking

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome libtool localbase meson pathfix \
		pkgconfig python:3.6+,build sqlite ssl tar:xz
USE_GNOME=	glib20 intlhack introspection:build \
		libxml2 referencehack
USE_LDCONFIG=	yes
MESON_ARGS=	-Dvapi=disabled \
		-Dgtk_doc=true \
		-Dgnome=true

LIBVERSION=	1.9.0
PLIST_SUB=	VERSION="2.4" LIBVERSION=${LIBVERSION}

.include <bsd.port.mk>
