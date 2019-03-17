# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yelp-xsl
PORTVERSION=	3.32.1
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	DocBook XSLT stylesheets for yelp

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL

BUILD_DEPENDS=	itstool:textproc/itstool

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome localbase pathfix \
		pkgconfig tar:xz
USE_GNOME=	gnomeprefix intlhack libxml2 libxslt
GNU_CONFIGURE=	yes
NO_ARCH=	yes

.include <bsd.port.mk>
