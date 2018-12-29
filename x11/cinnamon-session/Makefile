# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	cinnamon-session
PORTVERSION=	4.0.0
CATEGORIES=	x11 gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Session component for the cinnamon desktop

LICENSE=	GPLv2

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libxapp.so:x11/xapps \
		libcanberra.so:audio/libcanberra

#?
#RUN_DEPENDS=	console-kit-daemon:sysutils/consolekit2 \


USES=		gl gnome meson pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

USE_GNOME=	cairo gdkpixbuf2 gtk30
USE_XORG=	ice sm x11 xau xcomposite xext xrender xtst
USE_GL=		gl
INSTALLS_ICONS=	yes

GLIB_SCHEMAS=	org.cinnamon.SessionManager.gschema.xml
MESON_ARGS=	-Dwith-gconf=false


.include <bsd.port.mk>
