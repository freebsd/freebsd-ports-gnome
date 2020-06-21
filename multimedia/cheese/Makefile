# Created by: FreeBSD GNOME Team <gnome@freebsd.org>
# $FreeBSD$

PORTNAME=	cheese
PORTVERSION=	3.34.0
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Photobooth-inspired app for taking pictures and videos from webcam

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	v4l_compat>=0:multimedia/v4l_compat \
		gnome-video-effects>=0:graphics/gnome-video-effects \
		vala>=0.14.0:lang/vala \
		itstool:textproc/itstool
LIB_DEPENDS=	libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libcanberra.so:audio/libcanberra \
		libclutter-1.0.so:graphics/clutter \
		libcogl.so:graphics/cogl \
		libjson-glib-1.0.so:devel/json-glib \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libclutter-gst-3.0.so:multimedia/clutter-gst3
RUN_DEPENDS=	gnome-video-effects>=0:graphics/gnome-video-effects

PORTSCOUT=	limitw:1,even

USES=		gettext gl gnome localbase meson pathfix pkgconfig tar:xz xorg
USE_GNOME=	cairo intlhack evolutiondataserver3 librsvg2 \
		gnomedesktop3 libxml2:build introspection:build
USE_GL=		egl
USE_XORG=	xi xext xdamage xfixes xcomposite xrandr xxf86vm x11
USE_GSTREAMER1=	bad good jpeg ogg theora v4l2 vorbis vpx
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-Wno-format-nonliteral

DOCS=		AUTHORS COPYING ChangeLog NEWS README
GLIB_SCHEMAS=	org.gnome.Cheese.gschema.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	DOCS MANPAGES
#OPTIONS_DEFAULT=MANPAGES
OPTIONS_EXCLUDE=	MANPAGES # broken for now

DOCS_MESON_TRUE=	gtk_doc
DOCS_BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc

MANPAGES_MESON_TRUE=	man
MANPAGES_BUILD_DEPENDS=	docbook-xml>=0:textproc/docbook-xml \
			docbook-xsl>=0:textproc/docbook-xsl
MANPAGES_USE=	GNOME=libxslt:build

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
