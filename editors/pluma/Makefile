# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pluma
PORTVERSION=	1.13.1
CATEGORIES=	editors mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Small but powerful text editor for MATE Desktop Environment

BUILD_DEPENDS=	itstool:textproc/itstool \
		${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes
LIB_DEPENDS=	libenchant.so:textproc/enchant \
		libsoup-2.4.so:devel/libsoup
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gmake libtool pathfix pkgconfig \
		shebangfix tar:xz
USE_MATE=	desktop
USE_XORG=	sm x11
USE_GNOME=	gvfs intlhack libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

SHEBANG_FILES=	${WRKSRC}/plugins/externaltools/data/search-recursive.tool.in \
		${WRKSRC}/plugins/externaltools/data/switch-c.tool.in

GLIB_SCHEMAS=	org.mate.pluma.gschema.xml \
		org.mate.pluma.plugins.filebrowser.gschema.xml \
		org.mate.pluma.plugins.spell.gschema.xml \
		org.mate.pluma.plugins.time.gschema.xml

OPTIONS_DEFINE=	MATEGTK3

MATEGTK3_DESC=	build agains gtk3
MATEGTK3_CONFIGURE_ON=	--with-gtk=3.0 --disable-python
MATEGTK3_USE=	GNOME=gtk30,gtksourceview3
MATEGTK3_CONFIGURE_OFF=	--with-gtk=2.0
MATEGTK3_USE_OFF=	GNOME=gtk20,pygobject,gtksourceview2,pygtk2,pygtksourceview

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMATEGTK3}
PLIST_SUB+=	PYTHON="@comment "
.else
USES+=		python:2
PLIST_SUB+=	PYTHON=""
.endif

.include <bsd.port.mk>
