# $FreeBSD$

PORTNAME=	xapps
PORTVERSION=	1.6.10
PORTREVISION=	1
CATEGORIES=	x11 gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Cross-desktop libraries and common resources

LICENSE=	LGPL3
LICENSE_FILE?=	${WRKSRC}/COPYING.LESSER

PORTSCOUT=	limit:^[0-9.]+$$	# ignore master.mint* tags

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

SHEBANG_FILES=	files libxapp schemas status-applets test-scripts

USES+=	xorg

USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 introspection intltool \
		libgnomekbd

GLIB_SCHEMAS=	org.x.apps.gschema.xml
INSTALLS_ICONS=	yes

USE_XORG=	x11

USE_LDCONFIG=	yes

post-patch:
	# pygobject split to x11/py-xapps, as consumers (which may
	# or may not be in ports) can use either python version
	@${REINPLACE_CMD} -e "/subdir('pygobject')/d" ${WRKSRC}/meson.build
	# Adhere to our hier(7).
	@${MKDIR} ${WRKSRC}/files${PREFIX}
.	for d in bin share
		@${MV} ${WRKSRC}/files/usr/${d} ${WRKSRC}/files${PREFIX}
.	endfor
.endif

.include <bsd.port.mk>
