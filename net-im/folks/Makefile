# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	folks
PORTVERSION=	0.12.1
PORTREVISION=	3
CATEGORIES=	net-im
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to aggregates people from multiple sources

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vapigen:lang/vala
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libtelepathy-glib.so:net-im/telepathy-glib

USES=		gettext gnome meson localbase pkgconfig python:2.7,build \
		readline shebangfix tar:xz
USE_GNOME=	evolutiondataserver3 introspection:build
USE_LDCONFIG=	yes

MESON_ARGS=	-Dbluez_backend=false
SHEBANG_FILES=	tests/tools/manager-file.py

GLIB_SCHEMAS=	org.freedesktop.folks.gschema.xml

PLIST_SUB=	LIBVER=25 VERSION=44 LIBVERLONG=25.19.1

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	TRACKER
OPTIONS_DEFAULT=TRACKER
TRACKER_DESC=	Tracker backend

TRACKER_MESON_TRUE=	tracker_backend
TRACKER_LIB_DEPENDS=	libtracker-control-2.0.so:sysutils/tracker

.include <bsd.port.mk>
