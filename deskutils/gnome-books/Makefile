# $FreeBSD$

PORTNAME=	gnome-books
PORTVERSION=	3.32.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Access, organize and read your e-books on GNOME

LICENSE=	GPLv2+

LIB_DEPENDS=	libgjs.so:lang/gjs \
		libevdocument3.so:graphics/evince \
		libgepub-0.6.so:textproc/libgepub \
		libgd.so:graphics/gd \
                libtracker-sparql-2.0.so:sysutils/tracker \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3

USES=		gnome meson tar:xz
USE_GNOME=	cairo gdkpixbuf2 gnomedesktop3 gtk30 introspection

GLIB_SCHEMAS=	org.gnome.Books.enums.xml \
		org.gnome.books.gschema.xml

.include <bsd.port.mk>
