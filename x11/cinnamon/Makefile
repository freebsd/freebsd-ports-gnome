# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	cinnamon
PORTVERSION=	4.0.10
PORTREVISION=	1
CATEGORIES=	x11 gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Fork of GNOME Shell with layout similar to GNOME 2

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	ca_root_nss>0:security/ca_root_nss \
		gnome-autogen.sh:devel/gnome-common \
		gtkdocize:textproc/gtk-doc
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libmuffin.so:x11-wm/muffin \
		libcjs.so:lang/cjs \
		libcinnamon-menu-3.so:x11/cinnamon-menus \
		libsoup-2.4.so:devel/libsoup \
		libstartup-notification-1.so:x11/startup-notification \
		libpolkit-agent-1.so:sysutils/polkit \
		libatk-bridge-2.0.so:accessibility/at-spi2-atk \
		libcroco-0.6.so:textproc/libcroco \
		libcinnamon-desktop.so:x11/cinnamon-desktop \
		libjson-glib-1.0.so:devel/json-glib \
		libdrm.so:graphics/libdrm
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR} \
		ca_root_nss>0:security/ca_root_nss \
		gnome-themes-extra>3.0.0:x11-themes/gnome-themes-extra \
		caribou>0:accessibility/caribou \
		cinnamon-control-center:sysutils/cinnamon-control-center \
		cinnamon-screensaver:x11/cinnamon-screensaver \
		nemo:x11-fm/nemo \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyinotify>0:devel/py-pyinotify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py-pexpect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-pam>0:security/py-python-pam@${PY_FLAVOR} \
		metacity:x11-wm/metacity \
		tint2:x11/tint

USES=		autoreconf:build compiler:c11 gettext gl gmake gnome libtool pathfix \
		pkgconfig python:3.5+ shebangfix

USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 intltool introspection libxml2 pygobject3

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

SHEBANG_GLOB=	*.py
SHEBANG_FILES=	files/*

USE_XORG=	x11 xcomposite xdamage xext xfixes xi xrandr xtst

USE_GSTREAMER1=	yes

USE_GL=		gl

INSTALLS_ICONS=	yes

USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-ca-certificates=${LOCALBASE}/share/certs/ca-root-nss.crt
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.cinnamon.gschema.xml

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_DEFAULT=	DOCS NLS
OPTIONS_SUB=	yes

DOCS_CONFIGURE_ENABLE=	gtk-doc

NLS_RUN_DEPENDS=	cinnamon-translations>0:misc/cinnamon-translations

post-patch:
	@${MKDIR} ${WRKSRC}/files${PREFIX}
.for d in bin share
	@${MV} ${WRKSRC}/files/usr/${d} ${WRKSRC}/files${PREFIX}
.endfor
	@${MV} ${WRKSRC}/files/etc ${WRKSRC}/files${PREFIX}

	# Remove a broken link (is applications-merge used anywhere?)
	@${RM} ${WRKSRC}/files/${PREFIX}/etc/xdg/menus/cinnamon-applications-merged

	@${REINPLACE_CMD} -e 's|find|find ${WRKSRC}/files|g' \
		${WRKSRC}/files/Makefile.in

	# is this really needed?
	#@${REINPLACE_CMD} -e 's|const NM = imports.gi.NM;||g' \
	#	${WRKSRC}/files${PREFIX}/share/cinnamon/applets/network\@cinnamon.org/applet.js

	@${REINPLACE_CMD} -e 's|nm-applet;||g' \
		${WRKSRC}/files${PREFIX}/share/cinnamon-session/sessions/cinnamon.session \
		${WRKSRC}/files${PREFIX}/share/cinnamon-session/sessions/cinnamon2d.session

	@${REINPLACE_CMD} -e '/prefix/s|/usr|${PREFIX}|g ;\
		/datadir/s|/usr|${PREFIX}|g ;\
		/libdir/s|/usr|${PREFIX}|g ;\
		/libexecdir/s|/usr|${PREFIX}|g' \
			${WRKSRC}/files${PREFIX}/share/cinnamon/cinnamon-menu-editor/cme/config.py

	@${FIND} ${WRKSRC} -name \* | ${XARGS} ${EGREP} -l "/usr/share/cinnamon/locale" | \
		${XARGS} ${REINPLACE_CMD} -e "s|/usr/share/cinnamon/locale|${PREFIX}/share/locale|g"

	@${FIND} ${WRKSRC} -name \* | ${XARGS} ${EGREP} -l "/usr/share" | \
		${XARGS} ${REINPLACE_CMD} -e "s|/usr/share|${PREFIX}/share|g"

	@${FIND} ${WRKSRC} -name \* | ${XARGS} ${EGREP} -l "/usr/lib" | \
		${XARGS} ${REINPLACE_CMD} -e "s|/usr/lib|${PREFIX}/lib|g"

	@${FIND} ${WRKSRC} -name \* | ${XARGS} ${EGREP} -l "/usr/bin" | \
		${XARGS} ${REINPLACE_CMD} -e "s|/usr/bin|${PREFIX}/bin|g"

	@${REINPLACE_CMD} -e '/cs-bluetooth/d; /cs-network/d' \
			${WRKSRC}/files${PREFIX}/share/cinnamon/cinnamon-settings/cinnamon-settings.py

	#@${REINPLACE_CMD} -e 's/SIZE\/$$$$CONTEXT/CONTEXT\/$$$$SIZE/g' \
	#		${WRKSRC}/data/icons/Makefile.am

# Some python files use #! /usr/bin/python (note the space between the bang and the python interpreter
	@${FIND} ${WRKSRC} -name \* | ${XARGS} ${EGREP} -l "#!.*\/usr\/bin\/python" | \
		${XARGS} ${REINPLACE_CMD} -e "s|#!.*python.*|#!/usr/bin/env python|g"

	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${FIND} ${WRKSRC} -name '*.bak' -delete

pre-configure:
	@cd ${WRKSRC} && ${SETENV} NOCONFIGURE=yes ${SH} autogen.sh

.include <bsd.port.mk>
