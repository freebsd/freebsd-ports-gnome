# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libchamplain
PORTVERSION=	0.12.20
CATEGORIES=	graphics
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C library aimed to provide a Gtk+ widget to display rasterized maps and markers

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libcogl.so:graphics/cogl \
		libclutter-1.0.so:graphics/clutter \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libsoup-2.4.so:devel/libsoup

USES=		gettext-runtime gnome localbase:ldflags meson \
		pkgconfig sqlite tar:xz
USE_GNOME=	cairo gdkpixbuf2 gtk30 introspection:build
USE_LDCONFIG=	yes
MESON_ARGS=	-Dmemphis=false \
		-Dgtk_doc=false

PLIST_SUB=	VERSION=0.12

.include <bsd.port.mk>
