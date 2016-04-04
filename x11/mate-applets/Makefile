# $FreeBSD$

PORTNAME=	mate-applets
PORTVERSION=	1.13.0
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
		libnotify.so:devel/libnotify

PORTSCOUT=	limitw:1,even

USES=		autoreconf:build gettext gmake libtool pathfix pkgconfig python tar:xz
USE_MATE=	desktop icontheme libmateweather panel polkit settingsdaemon
USE_XORG=	x11
USE_GNOME=	gdkpixbuf2 introspection:build \
		libxml2 libxslt pygobject pygobject3 intlhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ENV=	OS_SYS="/usr/include"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.panel.applet.charpick.gschema.xml \
		org.mate.panel.applet.command.gschema.xml \
		org.mate.panel.applet.geyes.gschema.xml \
		org.mate.panel.applet.multiload.gschema.xml \
		org.mate.panel.applet.netspeed.gschema.xml \
		org.mate.panel.applet.timer.gschema.xml \
		org.mate.stickynotes.gschema.xml

FIX_APPLETS=	accessx-status battstat \
		invest-applet/data stickynotes trashapplet

OPTIONS_DEFINE=	MATEGTK3

MATEGTK3_DESC=	build agains gtk3
MATEGTK3_CONFIGURE_ON=	--with-gtk=3.0
MATEGTK3_USE=	GNOME=gtk30,gtksourceview3,libwnck3
MATEGTK3_RUN_DEPENDS=	gucharmap:${PORTSDIR}/deskutils/gucharmap
MATEGTK3_CONFIGURE_OFF=	--with-gtk=2.0
MATEGTK3_USE_OFF=	GNOME=gtk20,gtksourceview2,libwnck

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

post-patch:
	${MV} ${WRKSRC}/invest-applet/invest/invest-applet.py \
		${WRKSRC}/invest-applet/invest/mate-invest-applet.py
.for dir in ${FIX_APPLETS}
	@${REINPLACE_CMD} -e 's|@LIBEXECDIR@/|@LIBEXECDIR@/mate-|g' \
		${WRKSRC}/${dir}/org.mate.*
.endfor
.for dir in command timerapplet
	@${REINPLACE_CMD} -e 's|(libexecdir)/|(libexecdir)/mate-|g' \
		${WRKSRC}/${dir}/Makefile.in
.endfor

.include <bsd.port.post.mk>
