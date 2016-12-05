# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-control-center
PORTVERSION=	3.22.1
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Control center for GNOME 3 project

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gnome-settings-daemon>=3.4.0:sysutils/gnome-settings-daemon \
		gsettings-desktop-schemas>=3.2.2:devel/gsettings-desktop-schemas \
		docbook-xsl>=0:textproc/docbook-xsl \
		iso-codes>=0:misc/iso-codes
LIB_DEPENDS=	libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libcanberra.so:audio/libcanberra \
		libpulse.so:audio/pulseaudio \
		libfontconfig.so:x11-fonts/fontconfig \
		libjson-glib-1.0.so:devel/json-glib \
		libfreetype.so:print/freetype2 \
		libcogl.so:graphics/cogl \
		libupower-glib.so:sysutils/upower \
		libaccountsservice.so:sysutils/accountsservice \
		libcolord.so:graphics/colord \
		libcolord-gtk.so:graphics/colord-gtk \
		libibus-1.0.so:textproc/ibus \
		libgoa-1.0.so:net/gnome-online-accounts \
		libpwquality.so:security/libpwquality \
		libgtop-2.0.so:devel/libgtop \
		libgrilo-0.3.so:net/grilo \
		libpolkit-gobject-1.so:sysutils/polkit \
		libsoup-2.4.so:devel/libsoup
RUN_DEPENDS=	gnome-settings-daemon>=3.4.0:sysutils/gnome-settings-daemon \
		gsettings-desktop-schemas>=3.2.2:devel/gsettings-desktop-schemas \
		iso-codes>=0:misc/iso-codes \
		glxinfo:graphics/mesa-demos \
		apg:security/apg \
		gcm-calibrate:graphics/gnome-color-manager

CONFLICTS=	gnome-media-2.[0-9]*
PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lib gettext gmake gnome localbase pathfix \
		pkgconfig ssl tar:xz
USE_GNOME=	cairo gnomedesktop3 intltool libxml2
USE_GL=		egl
USE_XORG=	xext xdamage xfixes xcomposite xrandr xscrnsaver x11 xxf86misc kbproto xi
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	CUPS
OPTIONS_DEFAULT=CUPS
CUPS_DESC=	Cups (printing) support
CHEESE_DESC=	Cheese webcam support

OPTIONS_DEFINE_i386=	CHEESE
OPTIONS_DEFAULT_i386=	CHEESE
OPTIONS_DEFINE_amd64=	CHEESE
OPTIONS_DEFAULT_amd64=	CHEESE
CUPS_LIB_DEPENDS=	libcups.so:print/cups \
			libsmbclient.so:net/samba-libsmbclient
CUPS_CONFIGURE_ENABLE=	cups
CHEESE_LIB_DEPENDS=	libcheese.so:multimedia/cheese
CHEESE_CONFIGURE_WITH=	cheese

post-patch:
	@${REINPLACE_CMD} -e 's|datetime wacom|datetime|g' \
		${WRKSRC}/panels/Makefile.in

.include <bsd.port.mk>
