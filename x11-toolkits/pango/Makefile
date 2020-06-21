# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pango
PORTVERSION=	1.44.7
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

PATCH_SITES=	https://gitlab.gnome.org/GNOME/pango/commit/
PATCHFILES+=	3981fff79b368ab007cb1e977741a7fd7bb96821.diff:-p1 \
		0b3cd20be5249c51ec981a66c07a39d54d1d1c9d.diff:-p1

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Open-source framework for the layout and rendering of i18n text

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	help2man:misc/help2man
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libfontconfig.so:x11-fonts/fontconfig \
		libfribidi.so:converters/fribidi
RUN_DEPENDS=	xorg-fonts-truetype>0:x11-fonts/xorg-fonts-truetype \
		${FONTENCOD}:x11-fonts/encodings

USES=		compiler:c11 gettext gnome localbase meson pkgconfig tar:xz xorg
USE_LDCONFIG=	yes
USE_GNOME=	cairo glib20 introspection:build
USE_XORG=	x11 xft xrender

VERSION=	1.8.0
LIBVERSION=	0.4400.7
PLIST_SUB+=	VERSION=${VERSION} LIBVERSION=${LIBVERSION}

PORTSCOUT=	limitw:1,even

FONTSCALE=	${LOCALBASE}/share/fonts/TTF/luximb.ttf
FONTENCOD=	${LOCALBASE}/share/fonts/encodings/encodings.dir

pre-configure:
# .if !exists() evaluates too early before cairo has a chance to be installed
	@if ! pkg-config --exists cairo-gobject; then \
		${ECHO_MSG} "${PKGNAME}: Needs cairo with GLIB (GObject) support enabled."; \
		${FALSE}; \
	fi

.include <bsd.port.mk>
