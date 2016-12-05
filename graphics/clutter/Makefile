# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clutter
PORTVERSION=	1.26.0
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	OpenGL based interactive canvas library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libcogl.so:graphics/cogl

PORTSCOUT=	limit:1,even

USES=		gettext gmake gnome libtool localbase pathfix \
		pkgconfig tar:xz
USE_GNOME=	gtk30 introspection:build
USE_GL=		gl egl
USE_XORG=	glproto x11 xfixes xdamage xcomposite xi
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-x --enable-conformance=no \
		--disable-evdev-input \
		--enable-egl-backend=yes \
		--enable-x11-backend=yes \
		--enable-gdk-backend=no \
		--enable-wayland-compositor=no
CPPFLAGS+=	-fno-omit-frame-pointer
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
