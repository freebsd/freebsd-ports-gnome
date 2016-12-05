# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-calendar
PORTVERSION=	3.22.1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Simple and beatiful calendar application for GNOME

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limitw:1,even

LIB_DEPENDS=	libical.so:devel/libical \
		libnss3.so:security/nss \
		libnspr4.so:devel/nspr \
		libsecret-1.so:security/libsecret \
		libsoup-2.4.so:devel/libsoup \
		libgoa-1.0.so:net/gnome-online-accounts

USES=		gettext gmake gnome libtool localbase pathfix \
		pkgconfig sqlite tar:xz
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	cairo evolutiondataserver3 gtk30 intlhack \
		introspection
GNU_CONFIGURE=	yes

GLIB_SCHEMAS=	org.gnome.calendar.enums.xml \
		org.gnome.calendar.gschema.xml

# for gcc 4.2.1
post-patch:
	@${REINPLACE_CMD} -e 's|-Wempty-body||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
