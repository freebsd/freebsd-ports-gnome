# $FreeBSD$

PORTNAME=	gnome-builder
PORTVERSION=	3.20.4
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	IDE for writing software for GNOME

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	intltool-update:textproc/intltool \
		itstool:textproc/itstool \
		vala:lang/vala \
		appstream-util:devel/appstream-glib
LIB_DEPENDS=	libgit2-glib-1.0.so:devel/libgit2-glib \
		libpeas-1.0.so:devel/libpeas \
		libdevhelp-3.so:devel/devhelp \
		libgjs.so:lang/gjs \
		libpcre.so:devel/pcre
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py${PYTHON_SUFFIX}-sqlite3

PORTSCOUT=	limitw:1,even
PORTDOCS=	*

USES=		compiler:c++11-lib cpe desktop-file-utils gettext gmake \
		libtool localbase pathfix pkgconfig python:3 tar:xz
USE_GNOME=	glib20 gtk30 gtksourceview3 gtk-update-icon-cache py3gobject3
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-debug
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
CPE_VENDOR=	gnome
PLIST_SUB=	PORTVERSION=${PORTVERSION} \
		PYTHON_SUFFIX=${PYTHON_SUFFIX}

GLIB_SCHEMAS=	org.gnome.builder.code-insight.gschema.xml \
		org.gnome.builder.editor.gschema.xml \
		org.gnome.builder.editor.language.gschema.xml \
		org.gnome.builder.extension-type.gschema.xml \
		org.gnome.builder.gschema.xml \
		org.gnome.builder.project-tree.gschema.xml \
		org.gnome.builder.workbench.gschema.xml

.include <bsd.port.pre.mk>

.if defined(PYTHON_REL)
.if ${PYTHON_REL} < 3500
PYOEXTENSION=	pyo
.else
PYOEXTENSION=	opt-1.pyc
.endif
.endif

PLIST_SUB+=	PYOEXTENSION=${PYOEXTENSION}

.include <bsd.port.post.mk>
