# Created by: Gea-Suan Lin <gslin@gslin.org>

PORTNAME=	Net-IP-RangeCompare
PORTVERSION=	4.025
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl extension for IP Range Comparisons

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Data-IPV4-Range-Parse>=0.05:net/p5-Data-IPV4-Range-Parse \
		p5-Data-Range-Compare>=1.030:devel/p5-Data-Range-Compare

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
