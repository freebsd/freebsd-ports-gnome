# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtranslator
PORTVERSION=	3.32.0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME application for creating GNU gettext translation files

LICENSE=	GPLv3

BUILD_DEPENDS=	iso-codes>=0:misc/iso-codes \
		itstool:textproc/itstool \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libpeas-1.0.so:devel/libpeas \
		libgettextpo.so:devel/gettext-tools \
		libgspell-1.so:textproc/gspell \
		libjson-glib-1.0.so:devel/json-glib
RUN_DEPENDS=	iso-codes>=0:misc/iso-codes \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

USES=		desktop-file-utils gettext gnome localbase:ldflags meson \
		pkgconfig python:3.5+,build tar:xz
USE_GNOME=	cairo gtk30 libgda5 gtksourceview4 libxml2 introspection

USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
BINARY_ALIAS=	python3=${PYTHON_VERSION}

GLIB_SCHEMAS=	org.gnome.Gtranslator.gschema.xml \
		org.gnome.gtranslator.plugins.translation-memory.gschema.xml

.include <bsd.port.mk>
