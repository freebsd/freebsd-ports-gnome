# $FreeBSD$

PORTNAME=	mate-applets
PORTVERSION=	1.16.0
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Applets components for the MATE Desktop Environment

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgtop-2.0.so:devel/libgtop \
		libxklavier.so:x11/libxklavier \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libpolkit-gobject-1.so:sysutils/polkit \
		libhal.so:sysutils/hal \
		libupower-glib.so:sysutils/upower \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libnotify.so:devel/libnotify
RUN_DEPENDS=	gucharmap:deskutils/gucharmap

PORTSCOUT=	limitw:1,even

USES=		autoreconf:build gettext gmake libtool localbase pathfix \
		pkgconfig python tar:xz
USE_MATE=	desktop icontheme libmateweather panel polkit settingsdaemon
USE_XORG=	ice sm x11
USE_GNOME=	cairo gdkpixbuf2 gtk30 gtksourceview3 introspection:build \
		libwnck3 libxml2 libxslt pygobject pygobject3 intlhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ENV=	OS_SYS="/usr/include"
CONFIGURE_ARGS=	--with-gtk=3.0
LDFLAGS+=	-lpthread
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.panel.applet.charpick.gschema.xml \
		org.mate.panel.applet.command.gschema.xml \
		org.mate.panel.applet.geyes.gschema.xml \
		org.mate.panel.applet.multiload.gschema.xml \
		org.mate.panel.applet.netspeed.gschema.xml \
		org.mate.panel.applet.timer.gschema.xml \
		org.mate.stickynotes.gschema.xml

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" && ${ARCH} != "amd64"
CONFIGURE_ARGS+=--disable-battstat
CFLAGS+=	-fPIC
PLIST_SUB+=	BATTERY="@comment "
.else
#CONFIGURE_ARGS+=--enable-battstat
GLIB_SCHEMAS+=	org.mate.panel.applet.battstat.gschema.xml
PLIST_SUB+=	BATTERY=""
.endif

# requires linux libcpufreq library
#.if ${ARCH} != "i386" && ${ARCH} != "amd64"
CONFIGURE_ARGS+=--disable-cpufreq
PLIST_SUB+=	CPUFREQ="@comment "
#.else
#CONFIGURE_ARGS+=--enable-cpufreq
#PLIST_SUB+=	CPUFREQ=""
#GLIB_SCHEMAS+=	org.mate.panel.applet.cpufreq.gschema.xml
#.endif

.include <bsd.port.post.mk>
