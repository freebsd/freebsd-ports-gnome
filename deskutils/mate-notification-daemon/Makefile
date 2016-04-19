# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$

PORTNAME=	mate-notification-daemon
PORTVERSION=	1.14.0
CATEGORIES=	deskutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Send small notifications to your desktop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libnotify.so:devel/libnotify

PORTSCOUT=	limitw:1,even

USES=		gettext gmake libtool localbase pathfix \
		pkgconfig tar:xz
USE_XORG=	x11
USE_GNOME=	glib20 librsvg2 intlhack
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-dbus-services=${PREFIX}/share/dbus-1/services \
		--disable-static
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.NotificationDaemon.gschema.xml

OPTIONS_DEFINE=	MATEGTK3

MATEGTK3_DESC=	build agains gtk3
MATEGTK3_CONFIGURE_ON=	--with-gtk=3.0
MATEGTK3_USE=	GNOME=gtk30,libwnck3
MATEGTK3_CONFIGURE_OFF=	--with-gtk=2.0
MATEGTK3_USE_OFF=	GNOME=gtk20,libwnck

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMATEGTK3}
LIB_DEPENDS+=	libcanberra-gtk3.so:audio/libcanberra-gtk3
.else
LIB_DEPENDS+=	libcanberra-gtk.so:audio/libcanberra
.endif

.include <bsd.port.mk>
