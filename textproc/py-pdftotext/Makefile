# $FreeBSD$

PORTNAME=	pdftotext
<<<<<<< HEAD
PORTVERSION=	2.1.2
PORTREVISION=	2
=======
PORTVERSION=	2.1.4
PORTREVISION=	1
>>>>>>> upstream/master
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Simple PDF text extraction

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpoppler.so:graphics/poppler

USES=		compiler:c11 python
USE_PYTHON=	autoplist distutils

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
