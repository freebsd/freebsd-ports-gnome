# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-terminal
PORTVERSION=	1.16.1
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Terminal component for the MATE Desktop

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgnutls.so:security/gnutls

PORTSCOUT=	limitw:1,even

USES=		gettext gmake localbase pathfix pkgconfig \
		shebangfix tar:xz
USE_MATE=	desktop
USE_XORG=	ice sm x11
USE_GNOME=	cairo dconf gdkpixbuf2 gtk30 intlhack vte3
SHEBANG_FILES=	mate-terminal.wrapper
GNU_CONFIGURE=	yes

GLIB_SCHEMAS=	org.mate.terminal.gschema.xml

.include <bsd.port.mk>
