# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>

PORTNAME=	ptpd
DISTVERSION=	2.3.1
CATEGORIES=	net
PKGNAMESUFFIX=	2

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Implementation of the precision time protocol IEEE 1588-2008

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	ptpd
GH_TAGNAME=	d27a6e0

CONFLICTS=	ptpd2-devel.*

ETCDIR=	${PREFIX}/etc/${PORTNAME}${PKGNAMESUFFIX}

GNU_CONFIGURE=	yes
USES=		autoreconf gmake libtool

PORTDOCS=	*

USE_RC_SUBR=	ptpd2

OPTIONS_DEFINE=	DOCS SNMP
OPTIONS_DEFAULT=SNMP

SNMP_CONFIGURE_ENABLE=	snmp
SNMP_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${CP} ${FILESDIR}/*.sample ${STAGEDIR}${ETCDIR}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
