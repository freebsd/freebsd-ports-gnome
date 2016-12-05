# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnote
PORTVERSION=	3.22.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ version of Tomboy, note taking application

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libpcre.so:devel/pcre \
		libgtkspell3-3.so:textproc/gtkspell3 \
		libenchant.so:textproc/enchant \
		libboost_filesystem.so:devel/boost-libs \
		libsecret-1.so:security/libsecret \
		libuuid.so:misc/e2fsprogs-libuuid

PORTSCOUT=	limitw:1,even

USE_GNOME=	gtk30 gtkmm30 intltool libxml2 libxslt
USE_XORG=	x11
USES=		desktop-file-utils compiler:c++11-lib gettext gmake \
		gnome libtool localbase pathfix pkgconfig tar:xz
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-dbus-service-dir=${PREFIX}/share/dbus-1/services
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.gnote.gschema.xml

DOCS=		AUTHORS ChangeLog NEWS README TODO

PLIST_SUB+=	VERSION=${PORTVERSION}

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
EXTRA_PATCHES=	${FILESDIR}/extra-src_base_macros.hpp
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
