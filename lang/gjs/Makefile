# Created by: Pawel Worach <pawel.worach@gmail.com>
# $FreeBSD$

PORTNAME=	gjs
PORTVERSION=	1.64.3
CATEGORIES=	lang gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME Javascript binding

LICENSE=	MPL11 LGPL20+ GPLv2+
LICENSE_COMB=	multi
LICENSE_FILE_MPL11=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL20+ =	${WRKSRC}/COPYING.LGPL

LIB_DEPENDS=	libmozjs-68.so:lang/spidermonkey68 \
		libffi.so:devel/libffi

USES=		compiler:c++14-lang gettext gnome localbase meson \
		pathfix pkgconfig readline tar:xz xorg
USE_GNOME=	cairo gdkpixbuf2 gtk30 introspection
USE_XORG=	x11 xext
MESON_ARGS=	-Dprofiler=disabled \
		-Dinstalled_tests=false
USE_LDCONFIG=	yes

PORTSCOUT=	limitw:1,even

.include <bsd.port.mk>
