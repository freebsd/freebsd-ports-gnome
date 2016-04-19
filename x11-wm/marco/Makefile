# Created by: Garrett Rooney <rooneg@electricjellyfish.net>
# $FreeBSD$

PORTNAME=	marco
PORTVERSION=	1.14.0
CATEGORIES=	x11-wm mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Window manager for the adult in you

BUILD_DEPENDS=	itstool:textproc/itstool \
		zenity>=3.0.0:x11/zenity
LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification \
		libgtop-2.0.so:devel/libgtop
RUN_DEPENDS=	zenity>=3.0.0:x11/zenity

PORTSCOUT=	limitw:1,even

USES=		gettext gmake libtool localbase pathfix pkgconfig tar:xz
USE_XORG=	x11 xcomposite xcursor xdamage xrandr
USE_GNOME=	gdkpixbuf2 glib20 intlhack pango
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=2.0
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.marco.gschema.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE= MATEGTK3

MATEGTK3_DESC=	build agains gtk3
MATEGTK3_CONFIGURE_ON=	--with-gtk=3.0
MATEGTK3_USE=	GNOME=gtk30
MATEGTK3_CONFIGURE_OFF=	--with-gtk=2.0
MATEGTK3_USE_OFF=	GNOME=gtk20

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMATEGTK3}
LIB_DEPENDS+=	libcanberra-gtk3.so:audio/libcanberra-gtk3
.else
LIB_DEPENDS+=	libcanberra-gtk.so:audio/libcanberra
.endif

.include <bsd.port.mk>
