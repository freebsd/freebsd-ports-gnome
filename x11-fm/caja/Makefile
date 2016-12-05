# Created by: ade, archie
# $FreeBSD$

PORTNAME=	caja
PORTVERSION=	1.16.1
CATEGORIES=	x11-fm mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	File manager for the MATE desktop

BUILD_DEPENDS=	gtkdoc-check:textproc/gtk-doc
LIB_DEPENDS=	libexif.so:graphics/libexif \
		libexempi.so:textproc/exempi \
		libunique-3.0.so:x11-toolkits/libunique3 \
		libstartup-notification-1.so:x11/startup-notification \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	${LOCALBASE}/libexec/gvfsd:devel/gvfs

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gmake libtool localbase \
		pathfix pkgconfig shared-mime-info tar:xz
USE_MATE=	desktop icontheme:run
USE_XORG=	ice sm x11 xext xrender
USE_GNOME=	cairo glib20 gtk30 intltool introspection:build \
		libxml2 pango
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-packagekit \
		--disable-gtk-doc \
		--with-gtk=3.0 \
		--with-html-dir=${PREFIX}/share/doc
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.caja.gschema.xml \
		org.mate.media-handling.gschema.xml

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/caja/extensions-2.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcaja-extension.so.1.4.0

.include <bsd.port.mk>
