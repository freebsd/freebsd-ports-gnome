# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	cinnamon-control-center
PORTVERSION=	4.6.0
CATEGORIES=	sysutils gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Control center for Cinnamon

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gnome-autogen.sh:devel/gnome-common \
		cinnamon-settings-daemon>=1.0.0:sysutils/cinnamon-settings-daemon \
		iso-codes>0:misc/iso-codes
LIB_DEPENDS=	libcinnamon-desktop.so:x11/cinnamon-desktop \
		libcinnamon-menu-3.so:x11/cinnamon-menus \
		libcolord.so:graphics/colord \
		libcolordprivate.so:graphics/colord \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libnotify.so:devel/libnotify \
		libpolkit-gobject-1.so:sysutils/polkit \
		libxklavier.so:x11/libxklavier \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	iso-codes>0:misc/iso-codes \
		cinnamon-settings-daemon>=1.0.0:sysutils/cinnamon-settings-daemon

USES=		autoreconf gettext gmake gnome libtool pathfix pkgconfig xorg

USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool libgnomekbd libxml2

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

USE_XORG=	x11 xfixes sm

INSTALLS_ICONS=	yes

USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-networkmanager \
		--disable-modemmanager
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	COLORD ONLINEACCOUNTS WACOM
OPTIONS_DEFAULT=COLORD ONLINEACCOUNTS WACOM
OPTIONS_SUB=	yes

ONLINEACCOUNTS_DESC=	GNOME Online Accounts panel support
WACOM_DESC=	Wacom management panel support

COLORD_LIB_DEPENDS=	libcolord.so:graphics/colord
COLORD_CONFIGURE_ENABLE=	color

ONLINEACCOUNTS_LIB_DEPENDS=	libgoa-1.0.so:net/gnome-online-accounts
ONLINEACCOUNTS_CONFIGURE_ENABLE=	onlineaccounts

WACOM_LIB_DEPENDS=	libwacom.so:x11/libwacom
WACOM_USE=		xorg=xi
WACOM_CONFIGURE_ENABLE=	wacom

.include <bsd.port.mk>
