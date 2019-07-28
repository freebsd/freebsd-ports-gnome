# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-sound-recorder
PORTVERSION=	3.32.1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME sound recorder application

LICENSE=	GPLv2+

LIB_DEPENDS=	libgjs.so:lang/gjs

USES=		gettext gnome localbase meson pkgconfig \
		python:3.4+ shebangfix tar:xz
USE_GNOME=	gtk30 intlhack introspection
USE_GSTREAMER1=	flac ogg pulse

INSTALLS_ICONS=	yes
PORTSCOUT=	limitw:1,even
SHEBANG_FILES=	build-aux/meson_post_install.py

GLIB_SCHEMAS=	org.gnome.SoundRecorder.gschema.xml

.include <bsd.port.mk>
