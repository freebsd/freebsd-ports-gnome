# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	cinnamon-settings-daemon
PORTVERSION=	4.0.3
CATEGORIES=	sysutils gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Cinnamon desktop settings daemon

BUILD_DEPENDS=	cinnamon-session:x11/cinnamon-session
LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libpolkit-gobject-1.so:sysutils/polkit \
		libgudev-1.0.so:devel/libgudev \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libcolord.so:graphics/colord \
		liblcms2.so:graphics/lcms2 \
		libcinnamon-desktop.so:x11/cinnamon-desktop \
		libxklavier.so:x11/libxklavier \
		libnspr4.so:devel/nspr \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libupower-glib.so:sysutils/upower \
		libpulse.so:audio/pulseaudio \
		libnotify.so:devel/libnotify
RUN_DEPENDS=	cinnamon-session:x11/cinnamon-session

USES=		autoreconf gmake gnome localbase libtool pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk30 libgnomekbd
USE_XORG=	x11 xext xfixes xi

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.cinnamon.settings-daemon.enums.xml \
		org.cinnamon.settings-daemon.peripherals.gschema.xml \
		org.cinnamon.settings-daemon.peripherals.wacom.gschema.xml \
		org.cinnamon.settings-daemon.plugins.color.gschema.xml \
		org.cinnamon.settings-daemon.plugins.gschema.xml \
		org.cinnamon.settings-daemon.plugins.housekeeping.gschema.xml \
		org.cinnamon.settings-daemon.plugins.media-keys.gschema.xml \
		org.cinnamon.settings-daemon.plugins.power.gschema.xml \
		org.cinnamon.settings-daemon.plugins.xrandr.gschema.xml \
		org.cinnamon.settings-daemon.plugins.xsettings.gschema.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	CUPS SMARTCARD
OPTIONS_DEFAULT=CUPS SMARTCARD

CUPS_CONFIGURE_ENABLE=	cups
CUPS_LIB_DEPENDS=	libcups.so:print/cups

SMARTCARD_DESC=	Smartcard support
SMARTCARD_CONFIGURE_ENABLE=	smartcard-support
SMARTCARD_LIB_DEPENDS=	libnss3.so:security/nss

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/gnome|${PREFIX}/etc/gnome|g' \
		${WRKSRC}/data/org.cinnamon.settings-daemon.plugins.xrandr.gschema.xml.in.in

.include <bsd.port.mk>
