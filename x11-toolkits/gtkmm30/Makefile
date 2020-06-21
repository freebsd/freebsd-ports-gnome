# Created by: Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
# $FreeBSD$

PORTNAME=	gtkmm
PORTVERSION=	3.24.2
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	30
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ wrapper for Gtk+3

LICENSE=	LGPL21

BUILD_DEPENDS=	gm4:devel/m4

USES=		compiler:c++11-lang gettext gmake gnome libtool \
		pkgconfig tar:xz
USE_CXXSTD=	c++11
USE_GNOME=	gdkpixbuf2 gtk30 glibmm cairomm atkmm pangomm

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-documentation
INSTALL_TARGET=	install-strip

PORTSCOUT=	limitw:1,even
PLIST_SUB=	API_VERSION="3.0"

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/tests//' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
