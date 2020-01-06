# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	epiphany
PORTVERSION=	3.32.6
CATEGORIES=	www gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Extremely lightweight and simple web browser for GNOME

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	iso-codes>=0:misc/iso-codes \
		itstool:textproc/itstool \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libsoup-2.4.so:devel/libsoup \
		libsoup-gnome-2.4.so:devel/libsoup-gnome \
		libsoup-2.4.so:devel/libsoup \
		libgcr-3.so:security/gcr \
		libstartup-notification-1.so:x11/startup-notification \
		libnss3.so:security/nss \
		libjson-glib-1.0.so:devel/json-glib \
		libicuuc.so:devel/icu \
		libavahi-gobject.so:net/avahi-app \
		libnotify.so:devel/libnotify \
		libgmp.so:math/gmp \
		libnettle.so:security/nettle \
		libsecret-1.so:security/libsecret \
		libdazzle-1.0.so:x11-toolkits/libdazzle \
		libhandy-0.0.so:x11-toolkits/libhandy \
		libp11-kit.so:security/p11-kit
RUN_DEPENDS=	iso-codes>=0:misc/iso-codes \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lib cpe desktop-file-utils gettext gnome \
		localbase:ldflags meson pkgconfig python:3.4+ shebangfix \
		sqlite tar:xz xorg
CPE_VENDOR=	gnome
USE_GNOME=	cairo gnomedesktop3 intlhack libwnck3 libxml2 libxslt
USE_XORG=	x11
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
MESON_ARGS=	-Db_lundef=false \
		-Dunit_tests=disabled
GLIB_SCHEMAS=	org.gnome.Epiphany.enums.xml \
		org.gnome.epiphany.gschema.xml
SHEBANG_FILES=	post_install.py

PLIST_SUB+=	EPHY_VERSION=${PORTVERSION:R}

.include <bsd.port.mk>
