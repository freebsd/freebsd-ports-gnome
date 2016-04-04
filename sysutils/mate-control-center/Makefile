# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-control-center
PORTVERSION=	1.13.2
CATEGORIES=	sysutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Control center for MATE project

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libcanberra-gtk.so:audio/libcanberra \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libxklavier.so:x11/libxklavier \
		libpolkit-gobject-1.so:sysutils/polkit

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gmake libtool pathfix pkgconfig \
		shared-mime-info tar:xz
USE_MATE=	desktop libmatekbd marco menus settingsdaemon
USE_XORG=	x11 xcursor xext xxf86misc xft xi xrandr xscrnsaver
USE_GNOME=	dconf glib20 intlhack libxml2 librsvg2 \
		pango
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-appindicator=no
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.control-center.gschema.xml \
		org.mate.control-center.keybinding.gschema.xml

OPTIONS_DEFINE=	MATEGTK3

MATEGTK3_DESC=	build agains gtk3
MATEGTK3_CONFIGURE_ON=	--with-gtk=3.0
MATEGTK3_USE=	GNOME=gtk30
MATEGTK3_LIB_DEPENDS=	libunique-3.0.so:x11-toolkits/libunique3
MATEGTK3_CONFIGURE_OFF=	--with-gtk=2.0
MATEGTK3_USE_OFF=	GNOME=gtk20

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:NMATEGTK3}
LIB_DEPENDS+=	libunique-1.0.so:x11-toolkits/unique
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/capplets/common/mate-theme-info.c
	@${REINPLACE_CMD} -e 's|/usr/sbin|${PREFIX}/sbin|g' \
		${WRKSRC}/capplets/display/org.mate.randr.policy.in

.include <bsd.port.mk>
