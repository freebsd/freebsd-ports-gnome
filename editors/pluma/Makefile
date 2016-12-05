# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pluma
PORTVERSION=	1.16.0
CATEGORIES=	editors mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Small but powerful text editor for MATE Desktop Environment

BUILD_DEPENDS=	itstool:textproc/itstool \
		${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes
LIB_DEPENDS=	libenchant.so:textproc/enchant \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libsoup-2.4.so:devel/libsoup

RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gmake libtool localbase \
		pathfix pkgconfig shebangfix tar:xz
USE_MATE=	desktop
USE_XORG=	ice sm x11
USE_GNOME=	cairo gdkpixbuf2 gvfs gtk30 gtksourceview3 intlhack libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-gtk=3.0 \
		--disable-python \
		--with-html-dir=${PREFIX}/share/doc
INSTALL_TARGET=	install-strip

SHEBANG_FILES=	${WRKSRC}/plugins/externaltools/data/search-recursive.tool.in \
		${WRKSRC}/plugins/externaltools/data/switch-c.tool.in

GLIB_SCHEMAS=	org.mate.pluma.gschema.xml \
		org.mate.pluma.plugins.filebrowser.gschema.xml \
		org.mate.pluma.plugins.spell.gschema.xml \
		org.mate.pluma.plugins.time.gschema.xml

.include <bsd.port.mk>
