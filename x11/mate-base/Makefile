# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD: head/x11/mate-base/Makefile 467271 2018-04-13 21:16:56Z ericbsd $

PORTNAME=	mate-base
PORTVERSION=	1.20.0
CATEGORIES=	x11 mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	"meta-port" for the MATE base integrated X11 desktop

USES=		metaport

RUN_DEPENDS=	${LOCALBASE}/share/fonts/dejavu/DejaVuSerif.ttf:x11-fonts/dejavu \
		${LOCALBASE}/share/hal/fdi/information/10freedesktop/10-camera-ptp.fdi:sysutils/hal-info \
		${LOCALBASE}/share/mate-background-properties/mate-desktop.xml:x11-themes/mate-backgrounds \
		mate-themes>=1.8.0:x11-themes/mate-themes \
		mate-icon-theme-faenza>=1.8.0:x11-themes/mate-icon-theme-faenza

USE_MATE=	caja:run controlcenter:run icontheme:run \
		marco:run notificationdaemon:run panel:run \
		polkit:run session:run

.include <bsd.port.mk>
