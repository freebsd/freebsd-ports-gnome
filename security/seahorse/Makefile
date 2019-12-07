# Created by: Dave McKay <dave@mu.org>
# $FreeBSD$

PORTNAME=	seahorse
PORTVERSION=	3.32
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME application for managing encryption keys (PGP, SSH)

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	gnupg>=2.2.0:security/gnupg \
		valac:lang/vala \
		itstool:textproc/itstool
LIB_DEPENDS=	libgpgme.so:security/gpgme \
		libgcr-3.so:security/gcr \
		libpwquality.so:security/libpwquality \
		libsecret-1.so:security/libsecret \
		libsoup-2.4.so:devel/libsoup
RUN_DEPENDS=	gnupg>=2.2.0:security/gnupg

USES=		gettext gnome localbase:ldflags meson \
		pkgconfig python:3.5+,build tar:xz xorg
USE_GNOME=	gtk30
USE_XORG=	sm

MESON_ARGS=	-Dcheck-compatible-gpg=false
INSTALLS_ICONS=	yes

PORTSCOUT=	limitw:1,even
BINARY_ALIAS=	python3=${PYTHON_VERSION}

GLIB_SCHEMAS=	org.gnome.seahorse.gschema.xml \
		org.gnome.seahorse.manager.gschema.xml \
		org.gnome.seahorse.window.gschema.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	LDAP AVAHI
OPTIONS_DEFAULT=LDAP AVAHI

LDAP_MESON_TRUE=	ldap-support
LDAP_USE=	OPENLDAP=yes
LDAP_DESC=	Support for keyservers using LDAP

AVAHI_DESC=	Support for DNS-SD key sharing
AVAHI_MESON_TRUE=	key-sharing
AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app

.include <bsd.port.mk>
