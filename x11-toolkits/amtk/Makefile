# $FreeBSD$

PORTNAME=	amtk
PORTVERSION=	5.0.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gtk+ GtkUIManager replacement based on GAction

LICENSE=	LGPL21

USES=		gmake gnome libtool tar:xz
USE_GNOME=	cairo gdkpixbuf2 gtk30

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
