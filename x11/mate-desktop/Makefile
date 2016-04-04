# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-desktop
PORTVERSION=	1.13.0
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Additional UI API for MATE

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification

PORTSCOUT=	limitw:1,even

USES=		bison gettext gmake libtool pathfix pkgconfig \
		python shebangfix tar:xz
USE_XORG=	x11 xrandr
USE_GNOME=	dconf gdkpixbuf2 intlhack introspection:build
SHEBANG_FILES=	tools/mpaste
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.accessibility-keyboard.gschema.xml \
		org.mate.accessibility-startup.gschema.xml \
		org.mate.applications-at-mobility.gschema.xml \
		org.mate.applications-at-visual.gschema.xml \
		org.mate.applications-browser.gschema.xml \
		org.mate.applications-office.gschema.xml \
		org.mate.applications-terminal.gschema.xml \
		org.mate.background.gschema.xml \
		org.mate.file-views.gschema.xml \
		org.mate.interface.gschema.xml \
		org.mate.lockdown.gschema.xml \
		org.mate.peripherals-keyboard.gschema.xml \
		org.mate.peripherals-mouse.gschema.xml \
		org.mate.sound.gschema.xml \
		org.mate.thumbnail-cache.gschema.xml \
		org.mate.thumbnailers.gschema.xml \
		org.mate.typing-break.gschema.xml \
		org.mate.debug.gschema.xml

OPTIONS_SUB=			yes
OPTIONS_DEFINE=			PASTE MATEGTK3
OPTIONS_DEFAULT=		PASTE
PASTE_CONFIGURE_ENABLE=		mpaste
PASTE_DESC=			Build the mate paste tool

MATEGTK3_DESC=	build agains gtk3
MATEGTK3_CONFIGURE_ON=	--with-gtk=3.0
MATEGTK3_USE=	GNOME=gtk30
MATEGTK3_CONFIGURE_OFF=	--with-gtk=2.0
MATEGTK3_USE_OFF=	GNOME=gtk20


.include <bsd.port.mk>
