# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-terminal
PORTVERSION=	1.14.0
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Terminal component for the MATE Desktop

BUILD_DEPENDS=	itstool:textproc/itstool

PORTSCOUT=	limitw:1,even

USES=		gettext gmake localbase pathfix pkgconfig \
		shebangfix tar:xz
USE_MATE=	desktop
USE_XORG=	sm x11
USE_GNOME=	dconf intlhack
SHEBANG_FILES=	mate-terminal.wrapper
GNU_CONFIGURE=	yes

GLIB_SCHEMAS=	org.mate.terminal.gschema.xml

OPTIONS_DEFINE=	MATEGTK3

MATEGTK3_DESC=	build agains gtk3
MATEGTK3_CONFIGURE_ON=	--with-gtk=3.0
MATEGTK3_USE=	GNOME=gtk30,vte3
MATEGTK3_CONFIGURE_OFF=	--with-gtk=2.0
MATEGTK3_USE_OFF=	GNOME=gtk20,vte

.include <bsd.port.mk>
