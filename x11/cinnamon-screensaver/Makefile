# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	cinnamon-screensaver
PORTVERSION=	2.8.0
CATEGORIES=	x11 gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Cinnamon screensaver and locker

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsettings-desktop-schemas>=3.2.0:devel/gsettings-desktop-schemas \
		gnome-common>=0:devel/gnome-common
LIB_DEPENDS=	libnotify.so:devel/libnotify \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libcinnamon-desktop.so:x11/cinnamon-desktop \
		libdbus-glib-1.so:devel/dbus-glib
RUN_DEPENDS=	pam_helper:security/pam_helper \
		gsettings-desktop-schemas>=3.2.0:devel/gsettings-desktop-schemas \
		gnome-keyring>=0:security/gnome-keyring

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

USES=		autoreconf gettext gmake libtool pathfix pkgconfig tar:xz
USE_XORG=	x11 xext xxf86vm xxf86misc xscrnsaver
USE_GNOME=	gnomedesktop3 gnomeprefix intltool libgnomekbd libxml2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS=		-I${LOCALBASE}/include -Wno-error=format-nonliteral
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-pam-prefix=${PREFIX}/etc/pam.d \
		--without-systemd
INSTALL_TARGET=	install-strip

#CONFIGURE_ARGS+=--enable-debug=yes

SUB_FILES+=	cinnamon-screensaver.pam

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/pam.d|${PREFIX}/etc/pam.d|g' \
		${WRKSRC}/src/gs-auth-pam.c
	@${REINPLACE_CMD} -e 's|find -min|find . -|g' \
		${WRKSRC}/files/Makefile.in \
		${WRKSRC}/data/screensavers/Makefile.in
	@${ECHO} "#define PASSWD_HELPER_PROGRAM \"/usr/local/bin/pam_helper\"" \
		>> ${WRKSRC}/config.h.in

post-install:
	${INSTALL_DATA} ${WRKDIR}/cinnamon-screensaver.pam \
		${STAGEDIR}${PREFIX}/etc/pam.d/cinnamon-screensaver
	${RM} -r ${STAGEDIR}${PREFIX}/etc/pam.d/pam.d/

.include <bsd.port.mk>
