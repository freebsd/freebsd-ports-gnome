# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-contacts
PORTVERSION=	3.22.1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Contacts manager for gnome

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vala>=0.14.0:lang/vala
LIB_DEPENDS=	libgoa-1.0.so:net/gnome-online-accounts \
		libchamplain-0.12.so:graphics/libchamplain \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libclutter-1.0.so:graphics/clutter \
		libgee-0.8.so:devel/libgee \
		libfolks.so:net-im/folks \
		libnotify.so:devel/libnotify \
		libplds4.so:devel/nspr \
		libsecret-1.so:security/libsecret \
		libsoup-2.4.so:devel/libsoup \
		libjson-glib-1.0.so:devel/json-glib \
		libgeocode-glib.so:net/geocode-glib \
		libtelepathy-glib.so:net-im/telepathy-glib \
		libcogl-path.so:graphics/cogl \
		libnss3.so:security/nss

PORTSCOUT=	limitw:1,even

USE_GL=		egl
USE_GNOME=	cairo evolutiondataserver3 gdkpixbuf2 gnomedesktop3 gtk30 \
		intlhack introspection:build
USE_XORG=	x11 xcomposite xdamage xext xfixes xi xrandr
USES=		gettext gmake gnome localbase pathfix perl5 \
		pkgconfig sqlite tar:xz
GNU_CONFIGURE=	yes
MAKE_ENV=	XDG_CACHE_HOME=${WRKDIR}

GLIB_SCHEMAS=	org.gnome.Contacts.enums.xml \
		org.gnome.Contacts.gschema.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	MANPAGES NLS
OPTIONS_DEFAULT=MANPAGES

OPTIONS_DEFINE_i386=	CHEESE
OPTIONS_DEFINE_amd64=	CHEESE
OPTIONS_DEFAULT_i386=	CHEESE
OPTIONS_DEFAULT_amd64=	CHEESE

MANPAGES_CONFIGURE_ENABLE=	man-pages
MANPAGES_USE=		GNOME=libxslt:build
MANPAGES_BUILD_DEPENDS=	docbook-xml>=0:textproc/docbook-xml \
			docbook-xsl>=0:textproc/docbook-xsl

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

CHEESE_DESC=		Cheese webcam support
CHEESE_CONFIGURE_WITH=	cheese
CHEESE_LIB_DEPENDS=	libcheese-gtk.so:multimedia/cheese

post-patch:
	# touch vala sources to force regen c sources to honor cheese setting
	${TOUCH} ${WRKSRC}/src/main.vala \
		${WRKSRC}/src/contacts-avatar-dialog.vala

.include <bsd.port.mk>
