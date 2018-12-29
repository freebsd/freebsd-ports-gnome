# $FreeBSD$

PORTNAME=	xapps
PORTVERSION=	1.4.5
CATEGORIES=	x11

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	apps

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

RUN_DEPENDS=	bash:shells/bash

USES=		gnome meson pkgconfig python:3.5+ shebangfix
USE_GNOME=	cairo gdkpixbuf2 gtk30 introspection libgnomekbd pygobject3
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

GLIB_SCHEMAS=	org.x.apps.gschema.xml

SHEBANG_FILES=	files/usr/bin/pastebin \
		files/usr/bin/upload-system-info \
		files/usr/bin/xfce4-set-wallpaper \
		schemas/meson_install_schemas.py \
		test-scripts/xapp-icon-chooser-dialog \
		test-scripts/xapp-kbd-layout-controller

post-install:
	cd ${WRKSRC}/files/usr/bin && ${COPYTREE_BIN} . \
		${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/files/usr/share && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/share/

.include <bsd.port.mk>
