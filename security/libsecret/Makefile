# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libsecret
PORTVERSION=	0.20.3
CATEGORIES=	security gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to access the secret service API

LICENSE=	LGPL21

BUILD_DEPENDS=	docbook-xsl>=0:textproc/docbook-xsl \
		gtkdoc-scan:textproc/gtk-doc \
		vala:lang/vala
LIB_DEPENDS=	libgcrypt.so:security/libgcrypt

USES=		gettext gnome localbase meson pkgconfig tar:xz
USE_GNOME=	glib20 libxslt:build intltool \
		introspection:build
USE_LDCONFIG=	yes
MESON_ARGS=	-Ddefault_library=both

.include <bsd.port.mk>
