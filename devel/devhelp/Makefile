# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	devhelp
PORTVERSION=	3.32.0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Developer help browser for GNOME 3

LICENSE=	GPLv3+
LICENSE_FILES=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3

USES=		compiler:c++11-lib gettext gnome localbase \
		meson pkgconfig python:3.3+,build tar:xz
USE_GNOME=	amtk cairo gtk30 introspection

PORTSCOUT=	limitw:1,even

INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

GLIB_SCHEMAS=	org.gnome.devhelp.gschema.xml \
		org.gnome.libdevhelp-3.gschema.xml

BINARY_ALIAS=	python3=${PYTHON_VERSION}

.include <bsd.port.mk>
