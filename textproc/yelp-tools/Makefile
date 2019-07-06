# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yelp-tools
PORTVERSION=	3.32.2
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Utilities to help manage documentation for Yelp and the web

LICENSE=	GPLv2+

BUILD_DEPENDS=	yelp-xsl>=0:textproc/yelp-xsl \
		itstool:textproc/itstool

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome pathfix pkgconfig tar:xz
USE_GNOME=	intlhack libxml2 libxslt
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
