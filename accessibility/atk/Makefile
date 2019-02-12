# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	atk
PORTVERSION=	2.31.90
CATEGORIES=	accessibility devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME accessibility toolkit (ATK)

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext gnome localbase meson pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build

USE_LDCONFIG=	yes

PORTSCOUT=	limitw:1,even

.include <bsd.port.mk>
