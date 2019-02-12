# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-sound-recorder
PORTVERSION=	3.31.90
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME sound recorder application

LIB_DEPENDS=	libgjs.so:lang/gjs

PORTSCOUT=	limitw:1,even

USES=		gettext gnome localbase meson pkgconfig \
		python:3.4+ shebangfix tar:xz
USE_GNOME=	gtk30 intlhack introspection
USE_GSTREAMER1=	flac ogg pulse
USE_LDCONFIG=	yes

SHEBANG_FILES=	build-aux/meson_post_install.py

GLIB_SCHEMAS=	org.gnome.SoundRecorder.gschema.xml

.include <bsd.port.mk>
