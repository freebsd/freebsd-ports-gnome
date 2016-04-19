# Created by: Eric Turgeon <ericturgeon@ghostbsd.org>
# $FreeBSD$

PORTNAME=	caja-extensions
PORTVERSION=	1.14.0
CATEGORIES=	deskutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Set of extensions for Caja

LIB_DEPENDS=	libgupnp-1.0.so:net/gupnp

PORTSCOUT=	limitw:1,even

USES=		gettext gmake libtool localbase pathfix \
		pkgconfig tar:xz
USE_MATE=	caja desktop
USE_GNOME=	glib20 gtk20 intlhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=2.0
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.Caja.Sendto.gschema.xml \
		org.mate.caja-open-terminal.gschema.xml

OPTIONS_DEFINE=	MATEGTK3

MATEGTK3_DESC=	build agains gtk3
MATEGTK3_CONFIGURE_ON=	--with-gtk=3.0
MATEGTK3_USE=	GNOME=gtk30
MATEGTK3_CONFIGURE_OFF=	--with-gtk=2.0
MATEGTK3_USE_OFF=	GNOME=gtk20

.include <bsd.port.mk>
