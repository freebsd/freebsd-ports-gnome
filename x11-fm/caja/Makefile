# Created by: ade, archie
# $FreeBSD$

PORTNAME=	caja
PORTVERSION=	1.13.1
CATEGORIES=	x11-fm mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	File manager for the MATE desktop

BUILD_DEPENDS=	gtkdoc-check:textproc/gtk-doc
LIB_DEPENDS=	libexif.so:graphics/libexif \
		libexempi.so:textproc/exempi
RUN_DEPENDS=	${LOCALBASE}/libexec/gvfsd:devel/gvfs

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gmake libtool pathfix pkgconfig \
		shared-mime-info tar:xz
USE_MATE=	desktop icontheme:run
USE_XORG=	ice x11 xrender
USE_GNOME=	glib20 intltool introspection:build \
		libxml2 pango
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-packagekit \
		--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.caja.gschema.xml \
		org.mate.media-handling.gschema.xml

OPTIONS_DEFINE=	MATEGTK3

MATEGTK3_DESC=	build agains gtk3
MATEGTK3_CONFIGURE_ON=	--with-gtk=3.0
MATEGTK3_USE=	GNOME=gtk30
MATEGTK3_CONFIGURE_OFF=	--with-gtk=2.0
MATEGTK3_USE_OFF=	GNOME=gtk20

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMATEGTK3}
LIB_DEPENDS+=	libunique-3.0.so:x11-toolkits/libunique3
.else
LIB_DEPENDS+=	libunique-1.0.so:x11-toolkits/unique
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/caja/extensions-2.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcaja-extension.so.1.4.0

.include <bsd.port.mk>
