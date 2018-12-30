# $FreeBSD$

PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

LICENSE_FILE=	${WRKSRC}/../COPYING.LESSER

RUN_DEPENDS=	xapps==${PORTVERSION}:x11/xapps

USES=		gnome meson pkgconfig python

USE_GNOME=	pygobject3

USE_PYTHON=	concurrent flavors

MASTERDIR=	${.CURDIR}/../xapps
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist
PLIST_FILES=	${PYTHON_SITELIBDIR}/gi/overrides/XApp.py
WRKSRC_SUBDIR=	pygobject

SLAVE_PORT=	yes

OPTIONS_EXCLUDE=	DOCS

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|exec|\'${PYTHON_CMD}\'|" ${WRKSRC}/meson.build

.include "${MASTERDIR}/Makefile"
