# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-user-docs
PORTVERSION=	3.32.2
CATEGORIES=	misc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME users guide

LICENSE=	CC-BY-3.0
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool

USES=		gettext-tools gmake gnome pathfix tar:xz
USE_GNOME=	libxml2:build

GNU_CONFIGURE=	yes
NO_ARCH=	yes
PORTSCOUT=	limitw:1,even

.include <bsd.port.mk>
