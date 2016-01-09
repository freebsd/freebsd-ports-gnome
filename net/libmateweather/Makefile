# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libmateweather
PORTVERSION=	1.12.1
CATEGORIES=	net mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to accessing online weather informations

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libsoup-2.4.so:${PORTSDIR}/devel/libsoup

PORTSCOUT=	limitw:1,even

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	libxml2 intlhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.weather.gschema.xml

OPTIONS_DEFINE=	MATEGTK3

MATEGTK3_DESC=	build agains gtk3
MATEGTK3_CONFIGURE_ON=	--with-gtk=3.0
MATEGTK3_USE=	GNOME=gtk30
MATEGTK3_CONFIGURE_OFF=	--with-gtk=2.0
MATEGTK3_USE_OFF=	GNOME=gtk20

.include <bsd.port.mk>
