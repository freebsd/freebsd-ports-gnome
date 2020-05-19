# $FreeBSD$

PORTNAME=	xreader
PORTVERSION=	2.6.0
CATEGORIES=	graphics print
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GTK multi-format document viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libxapp.so:x11/xapps \
		libpoppler-glib.so:graphics/poppler-glib \
		libsecret-1.so:security/libsecret

USES=		compiler:c11 desktop-file-utils gettext-tools gnome meson pkgconfig \
		python:3.5+,build shebangfix xorg

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

SHEBANG_FILES=	install-scripts test

USE_XORG=	ice sm x11

USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool introspection libxml2

MESON_ARGS=	-Dintrospection=true \
		-Dmathjax-directory=${PREFIX}/www/MathJax \
		-Dpixbuf=true \
		-Dpdf=true
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

GLIB_SCHEMAS=	org.x.reader.gschema.xml

OPTIONS_DEFINE=	COMICS DBUS DEBUG DJVU DVI EPUB HELP PREVIEWER PS T1LIB \
		THUMBNAILER TIFF XPS
OPTIONS_DEFAULT=	COMICS DBUS DJVU EPUB HELP PREVIEWER PS THUMBNAILER TIFF XPS

OPTIONS_SUB=	yes

COMICS_DESC=		Comic book archives support
COMICS_MESON_TRUE=	comics

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_MESON_TRUE=	enable_dbus

DEBUG_MESON_TRUE=	enable_debug deprecated_warnings

DJVU_DESC=		DJVU support
DJVU_LIB_DEPENDS=	libdjvulibre.so:graphics/djvulibre
DJVU_MESON_TRUE=	djvu

DVI_DESC=		DVI viewer support
DVI_LIB_DEPENDS=	libspectre.so:print/libspectre
DVI_USE=		tex=kpathsea
DVI_MESON_TRUE=		dvi

EPUB_DESC=		Epub support
EPUB_LIB_DEPENDS=	libwebkit2gtk-4.0.so:www/webkit2-gtk3
EPUB_RUN_DEPENDS=	MathJax>0:www/mathjax
EPUB_MESON_TRUE=	epub

HELP_DESC=		Install help files
HELP_RUN_DEPENDS=	yelp>0:x11/yelp
HELP_MESON_TRUE=	help_files

PREVIEWER_DESC=		Print previewer support
PREVIEWER_MESON_TRUE=	previewer

PS_LIB_DEPENDS=		libspectre.so:print/libspectre
PS_MESON_TRUE=		ps

T1LIB_DESC=		T1LIB for TYPE1 fonts to DVI (Enables DVI)
T1LIB_LIB_DEPENDS=	libt1.so:devel/t1lib
T1LIB_MESON_TRUE=	t1lib
T1LIB_IMPLIES=		DVI

THUMBNAILER_DESC=	Thumbnailer support
THUMBNAILER_MESON_TRUE=	thumbnailer

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_MESON_TRUE=	tiff

XPS_DESC=		XPS support
XPS_LIB_DEPENDS=	libgxps.so:graphics/libgxps
XPS_MESON_TRUE=		xps

post-patch:
	@${REINPLACE_CMD} -e '/gdkwayland/d' ${WRKSRC}/libdocument/ev-document-misc.h

.include <bsd.port.mk>
