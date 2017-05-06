# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	graphics

COMMENT=	GStreamer GL graphics plugin

#XXX depends checking

GST_PLUGIN=	gl
DIST=		bad

PLIST=		${.CURDIR}/pkg-plist

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

post-install:
	${INSTALL_DATA} ${WRKSRC}/pkgconfig/gstreamer-gl.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/gstreamer-gl-1.0.pc

.include "${MASTERDIR}/Makefile"
