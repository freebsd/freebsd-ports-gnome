# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libchamplain
PORTVERSION=	0.12.14
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C library aimed to provide a Gtk+ widget to display rasterized maps and markers

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libclutter-1.0.so:graphics/clutter \
		libcogl.so:graphics/cogl \
		libjson-glib-1.0.so:devel/json-glib \
		libsoup-gnome-2.4.so:devel/libsoup-gnome \
		libsoup-2.4.so:devel/libsoup

USES=		gettext-runtime gmake gnome libtool localbase pathfix \
		pkgconfig sqlite tar:xz
USE_GNOME=	cairo gdkpixbuf2 gtk30 introspection:build
USE_GL=		egl gl
USE_XORG=	x11 xcomposite xdamage xext xfixes xi xrandr
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-gtk-doc-html=no
INSTALL_TARGET=	install-strip

PLIST_SUB=	VERSION=0.12

.include <bsd.port.mk>
