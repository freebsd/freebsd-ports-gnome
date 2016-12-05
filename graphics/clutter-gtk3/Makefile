# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clutter-gtk
PORTVERSION=	1.8.2
CATEGORIES=	graphics
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GTK+ Integration library for Clutter

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libclutter-1.0.so:graphics/clutter \
		libcogl-path.so:graphics/cogl \
		libjson-glib-1.0.so:devel/json-glib

USES=		gettext gmake gnome libtool pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_GNOME=	cairo gdkpixbuf2 gnomeprefix gtk30 introspection
USE_GL=		egl
USE_XORG=	xcomposite xdamage xext xfixes xi xp xrandr x11
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
