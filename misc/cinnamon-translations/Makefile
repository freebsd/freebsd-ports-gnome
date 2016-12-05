# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	cinnamon-translations
PORTVERSION=	2.8.3
CATEGORIES=	misc x11 gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Translations for the cinnamon desktop

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

USES=		gettext-tools tar:xz
NO_CONFIGURE=	yes
INSTALL_TARGET=	all

post-patch:
	@${REINPLACE_CMD} -e 's|usr/share|${STAGEDIR}${PREFIX}/share|g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
