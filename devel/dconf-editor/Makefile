# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dconf-editor
PORTVERSION=	3.36.2
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Configuration database editor for GNOME

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vala>=0.40.0:lang/vala
LIB_DEPENDS=	libdconf.so:devel/dconf

PORTSCOUT=	limitw:1,even

USES=		gettext gnome localbase meson pkgconfig python:3.6+,build \
		shebangfix tar:xz
USE_GNOME=	gtk30
USE_LDCONFIG=	yes
BINARY_ALIAS=	python3=${PYTHON_CMD}
SHEBANG_FILES=	meson_post_install.py
INSTALLS_ICONS=	yes

GLIB_SCHEMAS=	ca.desrt.dconf-editor.gschema.xml

.include <bsd.port.mk>
