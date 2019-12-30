# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libsoup
PORTVERSION=	2.66.4
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	SOAP (Simple Object Access Protocol) implementation in C

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala \
		glib-networking>=2.29.18:net/glib-networking
LIB_DEPENDS=	libpsl.so:dns/libpsl
RUN_DEPENDS=	glib-networking>=2.29.18:net/glib-networking

PORTSCOUT=	limitw:1,even

USES=		gettext gnome meson pkgconfig sqlite tar:xz
USE_GNOME=	glib20 libxml2 introspection:build

USE_LDCONFIG=	yes

MESON_ARGS=	-Db_lundef=false
LIBVERSION=	1.8.0
PLIST_SUB=	VERSION="2.4" LIBVERSION=${LIBVERSION}

.if defined(SOUP_SLAVE)
USES+=		sqlite
LIB_DEPENDS+=	libsoup-2.4.so:devel/libsoup
MESON_ARGS+=	-Dgnome=true
.else
MESON_ARGS+=	-Dgnome=false
.endif

.if defined(SOUP_SLAVE)
post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/include/libsoup-2.4 \
		${STAGEDIR}${PREFIX}/share/locale \
		${STAGEDIR}${PREFIX}/share/vala
	${RM} ${STAGEDIR}${PREFIX}/lib/libsoup-2.4.so* \
		${STAGEDIR}${PREFIX}/lib/girepository-1.0/Soup-2.4.typelib \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/libsoup-2.4.pc \
		${STAGEDIR}${PREFIX}/share/gir-1.0/Soup-2.4.gir
.endif

.include <bsd.port.mk>
