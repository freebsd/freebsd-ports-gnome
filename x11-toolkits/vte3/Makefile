# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vte
PORTVERSION=	0.60.3
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Terminal widget with improved accessibility and I18N support

LICENSE=	LGPL21

BUILD_DEPENDS=	vapigen:lang/vala \
		bash:shells/bash
LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libfribidi.so:converters/fribidi \
		libpcre2-8.so:devel/pcre2

PORTSCOUT=	limitw:1,even

USES=		compiler:c++17-lang gettext gnome gperf localbase meson \
		pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool referencehack \
		introspection:build
MESON_ARGS=	-Dgir=true \
		-D_systemd=false

PLIST_SUB=	VERSION=2.91

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc
DOCS_MESON_TRUE=	docs

.include <bsd.port.mk>
