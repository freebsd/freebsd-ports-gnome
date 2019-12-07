# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
# NOTE: please keep zeitgeist in sysutils/qzeitgeist in sync

PORTNAME=	zeitgeist
PORTVERSION=	1.0.2
CATEGORIES=	sysutils
#MASTER_SITES=	https://launchpad.net/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}/${PORTVERSION}/+download/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Event logging framework

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	valac:lang/vala \
		rapper:textproc/raptor2 \
		${PYTHON_PKGNAMEPREFIX}rdflib>=4.1.1:textproc/py-rdflib@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/xdg/__init__.py:devel/py-xdg@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/dbus/__init__.py:devel/py-dbus@${PY_FLAVOR}

USES=		autoreconf gettext gmake gnome pathfix python:2.7 pkgconfig \
		libtool localbase shebangfix sqlite tar:xz
USE_GNOME=	intlhack glib20 introspection:build

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_COMMIT=	f6394278664b19210823d27e9c04d363f38bd33d

CONFIGURE_ARGS=	--disable-fts --disable-telepathy \
		--disable-downloads-monitor

SHEBANG_FILES=	data/ontology2code

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	DATAHUB
OPTIONS_DEFAULT=DATAHUB

DATAHUB_LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib
DATAHUB_USE=	gnome=cairo,gdkpixbuf2,gtk30
DATAHUB_CONFIGURE_ENABLE=	datahub
DATAHUB_DESC=	Passive loggers for Zeitgeist

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/systemd

.include <bsd.port.mk>
