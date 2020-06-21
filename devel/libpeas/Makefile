# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libpeas
PORTVERSION=	1.26.0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Next evolution of the Gedit plugins engine

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc

USES=		gettext gmake gnome meson pathfix pkgconfig python:3.5+ tar:xz
USE_GNOME=	cairo gtk30 intlhack introspection pygobject3
BINARY_ALIAS=	python3=${PYTHON_CMD}
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
MESON_ARGS=	-Dglade_catalog=false \
		-Dpython2=false \
		-Dpython3=true \
		-Dgtk_doc=true

# lua needs lua 5.1 and devel/lua-lgi. The latter is build for lua 5.2 however..
MESON_ARGS+=	-Dlua51=false

.include <bsd.port.mk>
