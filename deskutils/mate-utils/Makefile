# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-utils
PORTVERSION=	1.14.0
CATEGORIES=	deskutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE support utilities

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgtop-2.0.so:devel/libgtop \
		libcanberra-gtk.so:audio/libcanberra

PORTSCOUT=	limitw:1,even

USES=		gettext gmake libtool localbase pathfix \
		pkgconfig tar:xz
USE_MATE=	panel
USE_XORG=	x11 xext
USE_GNOME=	intlhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-maintainer-flags=no \
		--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.dictionary.gschema.xml \
		org.mate.disk-usage-analyzer.gschema.xml \
		org.mate.screenshot.gschema.xml \
		org.mate.search-tool.gschema.xml \
		org.mate.system-log.gschema.xml

OPTIONS_DEFINE=	MATEGTK3

MATEGTK3_DESC=	build agains gtk3
MATEGTK3_CONFIGURE_ON=	--with-gtk=3.0
MATEGTK3_USE=	GNOME=gtk30
MATEGTK3_CONFIGURE_OFF=	--with-gtk=2.0
MATEGTK3_USE_OFF=	GNOME=gtk20

.include <bsd.port.mk>
