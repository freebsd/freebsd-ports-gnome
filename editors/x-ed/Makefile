# $FreeBSD$

PORTNAME=	xed
DISTVERSION=	2.0.2
CATEGORIES=	editors gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Small but powerful text editor for GTK+3

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libenchant-2.so:textproc/enchant2 \
		libpeas-1.0.so:devel/libpeas \
		libxapp.so:x11/xapps

USES=		desktop-file-utils gettext-runtime gettext-tools gnome meson pkgconfig \
		python:3.5+,build python:run shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

SHEBANG_GLOB=	*.py

USE_XORG=	x11

USE_LDCONFIG=	yes

USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 gtksourceview3 introspection intltool \
		libxml2 pango
GLIB_SCHEMAS=	org.x.editor.gschema.xml \
		org.x.editor.plugins.filebrowser.gschema.xml \
		org.x.editor.plugins.time.gschema.xml \
		org.x.editor.plugins.wordcompletion.gschema.xml

OPTIONS_DEFINE=		DOCS GSPELL GVFS_METADATA
OPTIONS_DEFAULT=	DOCS GSPELL GVFS_METADATA
OPTIONS_SUB=		yes

DOCS_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc
DOCS_MESON_TRUE=	docs

GSPELL_DESC=		Spell checking using gspell
GSPELL_LIB_DEPENDS=	libgspell-1.so:textproc/gspell
GSPELL_MESON_TRUE=	enable_spell

GVFS_METADATA_DESC=	GVFS metadata
GVFS_MESON_TRUE=	enable_gvfs_metadata

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGSPELL}
GLIB_SCHEMAS+=		org.x.editor.plugins.spell.gschema.xml
.endif

.include <bsd.port.mk>
