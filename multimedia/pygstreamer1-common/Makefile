	# Created by: Koop Mast <kwm@rainbow-runner.nl>
# $FreeBSD$

PORTNAME=	gstreamer
PORTVERSION=	1.12.1
PORTREVISION=	0
CATEGORIES=	multimedia python
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-python/
PKGNAMEPREFIX?=	py
PKGNAMESUFFIX?=	1-common
DISTNAME=	gst-python-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT?=	Common files for GStreamer python bindings

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

SLAVE_PORT?=	no

USES=		gmake gnome libtool pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_GSTREAMER1=	yes
INSTALL_TARGET=	install-strip

PLIST_SUB=	VERSION="${GST_VERSION}"

.if ${SLAVE_PORT} == no
PORTSCOUT?=	limitw:1,even

USES+=		python:2.7,build
USE_GNOME+=	pygobject3:build

PLIST_FILES=	lib/gstreamer-1.0/libgstpythonplugin.so

BUILD_WRKSRC=	${WRKSRC}/plugin
INSTALL_WRKSRC=	${WRKSRC}/plugin

.else
PORTSCOUT=	ignore:1

. if ${SLAVE_PORT} == python2
USES+=          python:2.7
USE_GNOME+=	pygobject3
. endif

. if ${SLAVE_PORT} == python3
USES+=          python:3.3+
USE_GNOME+=	py3gobject3
. endif

. if ${SLAVE_PORT} != no
RUN_DEPENDS+=	pygstreamer1-common>=0:multimedia/pygstreamer1-common

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/lib/gstreamer-1.0/libgstpythonplugin.*
	@${RMDIR} ${STAGEDIR}${PREFIX}/lib/gstreamer-1.0
. endif
.endif

.include <bsd.port.mk>
