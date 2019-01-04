# $FreeBSD$

PORTNAME=	xapp
DISTVERSION=	1.4.0
CATEGORIES=	x11 gnome
DIST_SUBDIR=	gnome
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gnome@freebsd.org
COMMENT=	Python Xapp library

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR}

USES=		python

USE_PYTHON=	autoplist distutils

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
GH_PROJECT=	python-${PORTNAME}

.include <bsd.port.mk>
