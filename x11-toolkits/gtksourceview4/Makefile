# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtksourceview
PORTVERSION=	4.6.0
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	4
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Text widget that adds syntax highlighting to the GtkTextView widget

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vala:lang/vala
LIB_DEPENDS=	libfribidi.so:converters/fribidi

USES=		compiler:c11 gettext gnome meson pkgconfig tar:xz
USE_CSTD=	c11
USE_GNOME=	cairo gdkpixbuf2 gtk30 introspection:build libxml2

USE_LDCONFIG=	yes

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc
DOCS_MESON_TRUE=	gtk_doc

.include <bsd.port.mk>
