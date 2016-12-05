# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-maps
PORTVERSION=	3.22.1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Map application for GNOME 3

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	geoclue>=0:net/geoclue \
		itstool:textproc/itstool
LIB_DEPENDS=	libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libgeocode-glib.so:net/geocode-glib \
		libgee-0.8.so:devel/libgee \
		libchamplain-0.12.so:graphics/libchamplain \
		libfolks.so:net-im/folks \
		libgjs.so:lang/gjs \
		libsoup-2.4.so:devel/libsoup \
		librest-0.7.so:devel/librest \
		libjson-glib-1.0.so:devel/json-glib \
		libclutter-1.0.so:graphics/clutter \
		libcogl.so:graphics/cogl
RUN_DEPENDS=	geoclue>=0:net/geoclue

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome libtool localbase pathfix \
		pkgconfig tar:xz
USE_GNOME=	cairo gnomedesktop3 gtk30 intlhack libxml2
USE_GL=		egl
USE_LDCONFIG=	yes
USE_XORG=	x11 xcomposite xdamage xext xfixes xi xrandr
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.Maps.gschema.xml

.include <bsd.port.mk>
