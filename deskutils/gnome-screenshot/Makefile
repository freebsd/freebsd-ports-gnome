# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-screenshot
PORTVERSION=	3.32.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME utility for making picutures of your screen

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	appstream-builder:devel/appstream-glib
LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3

USES=		gettext gnome meson pkgconfig python:3.4+,build tar:xz xorg
USE_GNOME=	cairo gdkpixbuf2 gtk30
USE_XORG=	x11

PORTSCOUT=	limitw:1,even
BINARY_ALIAS=	python3=${PYTHON_VERSION}

GLIB_SCHEMAS=	org.gnome.gnome-screenshot.gschema.xml

OPTIONS_DEFINE=	INTEL_FIX
OPTIONS_SUB=	yes

# Workaround garbled screenshot when 3D hardware acceleration is enabled
# via x11-drivers/xf86-video-intel port
INTEL_FIX_DESC=		Don't try to use the gnome-shell interface
INTEL_FIX_EXTRA_PATCHES+=	${FILESDIR}/extra-patch-intel

.include <bsd.port.mk>
