# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tracker
PORTVERSION=	2.2.2
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Object database, tag/metadata database, search tool and indexer

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid \
		libsoup-2.4.so:devel/libsoup \
		libjson-glib-1.0.so:devel/json-glib \
		libicutu.so:devel/icu

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lib gettext gnome localbase:ldflags meson \
		pkgconfig python:3.4+,build shebangfix sqlite tar:xz
USE_GNOME=	glib20 intltool introspection:build libxml2 
USE_LDCONFIG=	yes

MESON_ARGS=	-Dnetwork_manager=disabled \
		-Dfunctional_tests=false \
		-Dunicode_support=icu \
		-Dsystemd_user_services=no \
		-Dbash_completion=no

GLIB_SCHEMAS=	org.freedesktop.Tracker.DB.gschema.xml \
		org.freedesktop.Tracker.FTS.gschema.xml \
		org.freedesktop.Tracker.Store.gschema.xml \
		org.freedesktop.Tracker.enums.xml \
		org.freedesktop.Tracker.gschema.xml
SHEBANG_FILES=	utils/g-ir-merge/g-ir-merge

PLIST_SUB=	LIBVER=0.202.0

.include <bsd.port.mk>
