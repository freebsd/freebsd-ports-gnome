# Created by: Vanilla I. Shu <vanilla@MinJe.com.TW>
# $FreeBSD$
# Please keep gtk30 in sync with the following x11-themes ports:
# adwaita-icon-theme, gnome-themes-standard and mate-themes

PORTNAME=	gtk
PORTVERSION=	3.24.20
CATEGORIES=	x11-toolkits
#MASTER_SITES=	GNOME/sources/gtk+/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMESUFFIX=	3
#DISTNAME=	gtk+-${PORTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gimp Toolkit for X11 GUI (current stable version)

LICENSE=	LGPL20

BUILD_DEPENDS=	at-spi2-atk>=0:accessibility/at-spi2-atk \
		docbook-xsl>0:textproc/docbook-xsl
LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libfribidi.so:converters/fribidi \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	hicolor-icon-theme>=0:misc/hicolor-icon-theme \
		adwaita-icon-theme>=0:x11-themes/adwaita-icon-theme \
		at-spi2-atk>=0:accessibility/at-spi2-atk \
		librsvg2>=0:graphics/librsvg2

USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	GNOME
GL_COMMIT=	db39ce2b1699acaf5d0ba160cf7cc68ccf6e16d6

USE_PERL5=	build
USE_LDCONFIG=	yes
USES=		compiler:c11 gettext gnome localbase meson pathfix perl5 \
		pkgconfig python:3.5+,build shebangfix tar:xz
USE_GNOME=	atk cairo gdkpixbuf2 introspection:build libxslt:build pango
MESON_ARGS=	-Dintrospection=true \
		-Dman=true
CPPFLAGS+=	-fno-omit-frame-pointer
INSTALLS_ICONS=	yes

PORTSCOUT=	limit:1,even

BINARY_ALIAS=	python3=${PYTHON_CMD}
SHEBANG_GLOB=	*.py

LIBVERSION=	0.2413.7
PLIST_SUB+=	LIBVERSION=${LIBVERSION}

GLIB_SCHEMAS=	org.gtk.Demo.gschema.xml \
		org.gtk.Settings.ColorChooser.gschema.xml \
		org.gtk.Settings.Debug.gschema.xml \
		org.gtk.Settings.EmojiChooser.gschema.xml \
		org.gtk.Settings.FileChooser.gschema.xml

OPTIONS_DEFINE=	BROADWAY CUPS CLOUDPRINT COLORD DOCS WAYLAND X11
OPTIONS_DEFAULT=BROADWAY CUPS COLORD WAYLAND X11
OPTIONS_SUB=	yes

BROADWAY_DESC=	Enable GDK Broadway backend for showing GTK+ in the webbrowser using HTML5 and web sockets.
BROADWAY_MESON_TRUE=	broadway_backend

COLORD_DESC=	Color profile support
COLORD_LIB_DEPENDS=	libcolord.so:graphics/colord
COLORD_MESON_YES=	colord

CUPS_LIB_DEPENDS=	libcups.so:print/cups

CLOUDPRINT_DESC=	Cloud printing support
CLOUDPRINT_USE=		gnome=libxml2
CLOUDPRINT_LIB_DEPENDS=	librest-0.7.so:devel/librest \
			libsoup-2.4.so:devel/libsoup \
			libjson-glib-1.0.so:devel/json-glib

DOCS_BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc
DOCS_MESON_TRUE=	gtk_doc

WAYLAND_DESC=		GDK Wayland backend
WAYLAND_MESON_TRUE=	wayland_backend
WAYLAND_BUILD_DEPENDS=	wayland-protocols>=0:graphics/wayland-protocols \
			v4l_compat>=0:multimedia/v4l_compat
WAYLAND_LIB_DEPENDS=	libwayland-egl.so:graphics/wayland \
			libxkbcommon.so:x11/libxkbcommon
WAYLAND_RUN_DEPENDS=	wayland-protocols>=0:graphics/wayland-protocols
WAYLAND_USES=		gl
WAYLAND_USE=		GL=egl

X11_MESON_TRUE=	x11_backend
X11_USES=	xorg
X11_USE=	XORG=xext,xrender,x11,xinerama,xi,xrandr,xcursor,xfixes,xdamage,xcomposite

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCUPS}
PRINT+=	cups
.endif

.if ${PORT_OPTIONS:MCLOUDPRINT}
PRINT+=	cloudprint
.endif

PRINT_BACKENDS!=	${ECHO_CMD} ${PRINT} | ${TR} ' ' ','

pre-configure:
# .if !exists() evaluates too early before cairo has a chance to be installed
	@if ! pkg-config --exists cairo-xlib; then \
		${ECHO_MSG} "${PKGNAME}: Needs cairo with X11 support enabled."; \
		${FALSE}; \
	fi

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-3.0/modules
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-3.0/${GTK3_VERSION}/engines
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-3.0/${GTK3_VERSION}/loaders

.include <bsd.port.mk>
