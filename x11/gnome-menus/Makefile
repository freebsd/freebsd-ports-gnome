# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-menus
PORTVERSION=	3.32.0
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Implementation of the FreeDesktop Desktop Menu Spec

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	multi

USES=		gettext gmake gnome libtool localbase pathfix pkgconfig python tar:xz
USE_GNOME=	glib20 gnomeprefix intlhack introspection:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
