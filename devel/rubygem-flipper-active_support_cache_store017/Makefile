# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	flipper-active_support_cache_store
PORTVERSION=	0.17.2
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	017

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	ActiveSupport::Cache store adapter for Flipper

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activesupport60>=4.2<7:devel/rubygem-activesupport60 \
		rubygem-flipper017>=${PORTVERSION}<0.18:devel/rubygem-flipper017

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^0\.17\.

.include <bsd.port.mk>
