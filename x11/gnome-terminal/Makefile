# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-terminal
PORTVERSION=	3.22.0
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Terminal component for the GNOME 3 Desktop

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		itstool:textproc/itstool \
		appstream-builder:devel/appstream-glib \
		vala:lang/vala
LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid \
		libgnutls.so:security/gnutls \
		libpcre2-8.so:devel/pcre2
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

PORTSCOUT=	limitw:1,even

USES=		cpe gettext gmake gnome libtool localbase pathfix \
		pkgconfig tar:xz
USE_GNOME=	cairo dconf gdkpixbuf2 gtk30 intlhack nautilus3 vte3
USE_XORG=	sm ice x11
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CPE_VENDOR=	gnome

GLIB_SCHEMAS=	org.gnome.Terminal.gschema.xml

OPTIONS_SUB=		yes
OPTIONS_DEFINE=		MIGRATION SEARCHPROVIDER
OPTIONS_DEFAULT=	SEARCHPROVIDER
SEARCHPROVIDER_DESC=	Gnome-shell search provider
SEARCHPROVIDER_CONFIGURE_ENABLE=	search-provider
SEARCHPROVIDER_BUILD_DEPENDS=	gnome-shell:x11/gnome-shell
SEARCHPROVIDER_RUN_DEPENDS=	gnome-shell:x11/gnome-shell
MIGRATION_CONFIGURE_ENABLE=	migration
MIGRATION_USE=		GNOME=gconf2
MIGRATION_DESC=		Profile migration to gsettings (pulls in gconf2)

.include <bsd.port.options.mk>

post-patch:
	@${TOUCH} ${WRKSRC}/aclocal.m4 ${WRKSRC}/Makefile.in \
		${WRKSRC}/configure ${WRKSRC}/config.h.in
.if ${OSVERSION} < 1000000
	@${REINPLACE_CMD} -e 's|-Wno-suggest-attribute=format||g ; \
		s|-Wno-unused-but-set-variable||g' \
		${WRKSRC}/src/Makefile.in
EXTRA_PATCHES+=	${FILESDIR}/extra-src_terminal-screen.c
.endif

post-install:
.for i in ca cs de el es fi fr gl
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/help/${i}/gnome-terminal/figures
.endfor

.include <bsd.port.mk>
