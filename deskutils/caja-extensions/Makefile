# Created by: Eric Turgeon <ericturgeon@ghostbsd.org>
# $FreeBSD$

PORTNAME=	caja-extensions
PORTVERSION=	1.16.0
CATEGORIES=	deskutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Set of extensions for Caja

LIB_DEPENDS=	libgupnp-1.0.so:net/gupnp \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libstartup-notification-1.so:x11/startup-notification \
		libdbus-glib-1.so:devel/dbus-glib \
		libdbus-1.so:devel/dbus

PORTSCOUT=	limitw:1,even

USES=		gettext gmake libtool localbase pathfix \
		pkgconfig tar:xz
USE_MATE=	caja desktop
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 intlhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=3.0
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.Caja.Sendto.gschema.xml \
		org.mate.caja-open-terminal.gschema.xml

.include <bsd.port.mk>
