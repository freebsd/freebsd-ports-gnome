# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	cinnamon
PORTVERSION=	4.6.0
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
		libdrm.so:graphics/libdrm \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR} \
		ca_root_nss>0:security/ca_root_nss \
		gnome-themes-extra>3.0.0:x11-themes/gnome-themes-extra \
		caribou>0:accessibility/caribou \
		cinnamon-control-center:sysutils/cinnamon-control-center \
		cinnamon-screensaver:x11/cinnamon-screensaver \
		nemo:x11-fm/nemo \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyinotify>0:devel/py-pyinotify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py-pexpect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-pam>0:security/py-python-pam@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tinycss>0:textproc/py-tinycss@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR} \
		timezonemap>0:misc/timezonemap \
		gnome-backgrounds>0:x11-themes/gnome-backgrounds \
		metacity:x11-wm/metacity \
		tint2:x11/tint

USES=		autoreconf:build compiler:c11 gettext gl gmake gnome libtool pathfix \
		pkgconfig python:3.5+ shebangfix xorg

USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 intltool introspection libxml2 pygobject3

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
GH_TAGNAME=	1ccef7d

SHEBANG_GLOB=	*.py
SHEBANG_FILES=	files/*

USE_XORG=	x11 xcomposite xdamage xext xfixes xi xrandr xtst

USE_GSTREAMER1=	yes

USE_GL=		gl

INSTALLS_ICONS=	yes

USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ca-certificates=${LOCALBASE}/share/certs/ca-root-nss.crt \
		--disable-networkmanager
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.cinnamon.gschema.xml

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_DEFAULT=	DOCS NLS
OPTIONS_SUB=	yes

DOCS_CONFIGURE_ENABLE=	gtk-doc

NLS_RUN_DEPENDS=	cinnamon-translations>0:misc/cinnamon-translations

post-patch:
	# Remove a broken link (is applications-merge used anywhere?)
	@${RM} ${WRKSRC}/files/etc/xdg/menus/cinnamon-applications-merged

	@${REINPLACE_CMD} -e '/prefix/s|/usr|${PREFIX}|g ;\
		/datadir/s|/usr|${PREFIX}|g ;\
		/libdir/s|/usr|${PREFIX}|g ;\
		/libexecdir/s|/usr|${PREFIX}|g' \
			${WRKSRC}/files/usr/share/cinnamon/cinnamon-menu-editor/cme/config.py

	@${FIND} ${WRKSRC} -name \* | ${XARGS} ${EGREP} -l "/usr/share/cinnamon/locale" | \
		${XARGS} ${REINPLACE_CMD} -e "s|/usr/share/cinnamon/locale|${PREFIX}/share/locale|g"

	@${FIND} ${WRKSRC} -name \* | ${XARGS} ${EGREP} -l "/usr/share" | \
		${XARGS} ${REINPLACE_CMD} -e "s|/usr/share|${PREFIX}/share|g"

	@${FIND} ${WRKSRC} -name \* | ${XARGS} ${EGREP} -l "/usr/lib" | \
		${XARGS} ${REINPLACE_CMD} -e "s|/usr/lib|${PREFIX}/lib|g"

	@${FIND} ${WRKSRC} -name \* | ${XARGS} ${EGREP} -l "/usr/bin" | \
		${XARGS} ${REINPLACE_CMD} -e "s|/usr/bin|${PREFIX}/bin|g"

	@${REINPLACE_CMD} -e '/cs-bluetooth/d; /cs-network/d' \
			${WRKSRC}/files/usr/share/cinnamon/cinnamon-settings/cinnamon-settings.py

	# Some python files use #! /usr/bin/python (note the space between the bang and the python interpreter
	@${FIND} ${WRKSRC} -name \* | ${XARGS} ${EGREP} -l "#!.*\/usr\/bin\/python" | \
		${XARGS} ${REINPLACE_CMD} -e "s|#!.*python.*|#!/usr/bin/env python|g"

	# gtk-doc builds erroneous documentation files otherwise
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${FIND} ${WRKSRC} -name '*.bak' -delete

pre-configure:
	@cd ${WRKSRC} && ${SETENV} NOCONFIGURE=yes ${SH} autogen.sh

post-install:
	# Ship the GNOME Backgrounds set
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/cinnamon-background-properties
	@${LN} -s ${PREFIX}/share/gnome-background-properties/adwaita.xml \
		${STAGEDIR}${PREFIX}/share/cinnamon-background-properties/adwaita.xml
	@${LN} -s ${PREFIX}/share/gnome-background-properties/gnome-backgrounds.xml \
		${STAGEDIR}${PREFIX}/share/cinnamon-background-properties/gnome-backgrounds.xml

.include <bsd.port.mk>
