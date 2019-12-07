# Created by: FreeBSD GNOME Team <gnome@freebsd.org>
# $FreeBSD$

PORTNAME=	quadrapassel
PORTVERSION=	3.32.0
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome quadrapassel

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vala:lang/vala \
		evdev-proto>=0:devel/evdev-proto \
		itstool:textproc/itstool \
		appstream-util:devel/appstream-glib
LIB_DEPENDS=	libclutter-1.0.so:graphics/clutter \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libmanette-0.2.so:games/libmanette \
		libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libcogl.so:graphics/cogl \
		libjson-glib-1.0.so:devel/json-glib

PORTSCOUT=	limitw:1,even

USES=		gettext gl gnome localbase meson \
		pkgconfig tar:xz xorg
USE_GNOME=	cairo gtk30 intlhack librsvg2 libxml2:build
INSTALLS_ICONS=	yes
USE_GL=		gl egl
USE_XORG=	x11 xcomposite xext xdamage xfixes xi xrandr

GLIB_SCHEMAS=	org.gnome.Quadrapassel.gschema.xml

.include <bsd.port.mk>
