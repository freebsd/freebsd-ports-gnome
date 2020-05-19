# $FreeBSD$

PORTNAME=	xed
PORTVERSION=	2.6.0
CATEGORIES=	editors

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Small but powerful text editor for GTK+3

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libenchant-2.so:textproc/enchant2 \
		libpeas-1.0.so:devel/libpeas \
		libxapp.so:x11/xapps
RUN_DEPENDS=	${LOCALBASE}/share/glib-2.0/schemas/org.gnome.desktop.interface.gschema.xml:devel/gsettings-desktop-schemas

USES=		compiler:c++11-lang desktop-file-utils gettext-runtime gettext-tools \
		gnome meson pkgconfig python:3.5+ shebangfix xorg

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

SHEBANG_GLOB=	*.py

USE_LDCONFIG=	yes
USE_XORG=	x11

USE_LDCONFIG=	yes

USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 gtksourceview3 introspection intltool \
		libxml2 pango
GLIB_SCHEMAS=	org.x.editor.gschema.xml \
		org.x.editor.plugins.filebrowser.gschema.xml \
		org.x.editor.plugins.time.gschema.xml \
		org.x.editor.plugins.wordcompletion.gschema.xml

PORTSCOUT=	limit:^[0-9.]+$$	# ignore master.mint* tags

OPTIONS_DEFINE=		DOCS GSPELL GVFS_METADATA
OPTIONS_DEFAULT=	DOCS GSPELL GVFS_METADATA
OPTIONS_SUB=		yes

DOCS_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc
DOCS_MESON_TRUE=	docs

GSPELL_DESC=		Spell checking support via gspell
GSPELL_LIB_DEPENDS=	libgspell-1.so:textproc/gspell
GSPELL_MESON_TRUE=	enable_spell
GSPELL_VARS=	GLIB_SCHEMAS+=org.x.editor.plugins.spell.gschema.xml

GVFS_METADATA_DESC=	GVFS metadata
GVFS_MESON_TRUE=	enable_gvfs_metadata

.include <bsd.port.mk>
