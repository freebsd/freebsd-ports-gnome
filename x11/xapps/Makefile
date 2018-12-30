# $FreeBSD$

PORTNAME=	xapps
DISTVERSION=	1.4.5
CATEGORIES=	x11 gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@freebsd.org
COMMENT=	Common library for X-Apps project

LICENSE=	LGPL3
LICENSE_FILE?=	${WRKSRC}/COPYING.LESSER

USES?=		gettext-tools:build gnome meson pkgconfig python:3.5+ \
		shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

SLAVE_PORT?=	no

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=	DOCS

DOCS_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc
DOCS_MESON_TRUE=	docs

.if ${SLAVE_PORT} == "no"
BUILD_DEPENDS=	vapigen:lang/vala
LIB_DEPENDS=	libxklavier.so:x11/libxklavier
RUN_DEPENDS=	bash:shells/bash

SHEBANG_FILES=	files/usr/bin/* schemas/*.py test-scripts/*

USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 introspection intltool \
		libgnomekbd

GLIB_SCHEMAS=	org.x.apps.gschema.xml
INSTALLS_ICONS=	yes

USE_XORG=	x11

USE_LDCONFIG=	yes

post-patch:
	# pygobject split to x11/py-xapps, as consumers need both python versions
	@${REINPLACE_CMD} -e "/subdir('pygobject')/d" ${WRKSRC}/meson.build
	# Adhere to our hier(7).
	@${MKDIR} ${WRKSRC}/files${PREFIX}
.for d in bin share
	@${MV} ${WRKSRC}/files/usr/${d} ${WRKSRC}/files${PREFIX}
.endfor
.endif

.include <bsd.port.mk>
