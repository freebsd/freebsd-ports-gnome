# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	eog
PORTVERSION=	3.31.90
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Eye Of Gnome image viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libpeas-gtk-1.0.so:devel/libpeas \
		liblcms2.so:graphics/lcms2
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lang desktop-file-utils gettext gnome jpeg \
		localbase meson pkgconfig python:build,3.4+ shebangfix tar:xz
USE_GNOME=	cairo librsvg2 gtk30 gnomedesktop3 introspection
USE_XORG=	x11
INSTALLS_ICONS=	yes
SHEBANG_FILES=	${WRKSRC}/meson_post_install.py

GLIB_SCHEMAS=	org.gnome.eog.enums.xml \
		org.gnome.eog.gschema.xml

PLIST_SUB+=	VERSION=3.0

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	EXIF
OPTIONS_DEFAULT=EXIF

EXIF_DESC=	Digital camera file meta-data support
EXIF_MESON_TRUE=	libexif
EXIF_LIB_DEPENDS=	libexif.so:graphics/libexif

.include <bsd.port.mk>
