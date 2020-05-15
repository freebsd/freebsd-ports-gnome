# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	cinnamon-screensaver
PORTVERSION=	4.4.1
CATEGORIES=	x11 gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Cinnamon screen saver and locker

LICENSE=	GPLv2+ LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	gsettings-desktop-schemas>=3.2.0:devel/gsettings-desktop-schemas \
		gnome-autogen.sh:devel/gnome-common
LIB_DEPENDS=	libaccountsservice.so:sysutils/accountsservice \
		libcinnamon-desktop.so:x11/cinnamon-desktop \
		libdbus-glib-1.so:devel/dbus-glib
RUN_DEPENDS=	${LOCALBASE}/lib/pam_gnome_keyring.so:security/gnome-keyring \
		${PYTHON_PKGNAMEPREFIX}cairo>0:graphics/py-cairo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setproctitle>0:devel/py-setproctitle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-xapp>0:x11/py-python-xapp@${PY_FLAVOR}

USES=		autoreconf gettext-tools gmake gnome libtool pathfix pkgconfig \
		python:3.5+ shebangfix xorg

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

USE_XORG=	x11 xext xinerama xrandr xscrnsaver

USE_GNOME=	cairo gdkpixbuf2 intltool introspection:build libgnomekbd pygobject3

INSTALLS_ICONS=	yes

SHEBANG_GLOB=	*.py

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pam-prefix=${PREFIX}/etc/pam.d
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

SUB_FILES+=	cinnamon-screensaver.pam

post-patch:
	@${REINPLACE_CMD} -e 's|find -m|find . -m|g' \
		${WRKSRC}/files/Makefile.in
	@${ECHO} "#define PASSWD_HELPER_PROGRAM \"${PREFIX}/bin/pam_helper\"" \
		>> ${WRKSRC}/config.h.in

post-install:
	${INSTALL_DATA} ${WRKDIR}/cinnamon-screensaver.pam \
		${STAGEDIR}${PREFIX}/etc/pam.d/cinnamon-screensaver
	${RM} -r ${STAGEDIR}${PREFIX}/etc/pam.d/pam.d/

.include <bsd.port.mk>
