##############################################################################
#
#    file                 : Makefile
#    created              : Sun Feb 23 15:13:29 UTC 2025
#    copyright            : (C) 2002 Apollonio Bossi
#
##############################################################################

ROBOT       = AOS_dds_hwloop
MODULE      = ${ROBOT}.so
MODULEDIR   = drivers/${ROBOT}
SOURCES     = ${ROBOT}.cpp

SHIPDIR     = drivers/${ROBOT}
SHIP        = ${ROBOT}.xml car1-trb1.rgb logo.rgb
SHIPSUBDIRS = 

PKGSUBDIRS  = ${SHIPSUBDIRS}
src-robots-AOS_dds_hwloop_PKGFILES = $(shell find * -maxdepth 0 -type f -print)
src-robots-AOS_dds_hwloop_PKGDIR   = ${PACKAGE}-${VERSION}/$(subst ${TORCS_BASE},,$(shell pwd))

include ${MAKE_DEFAULT}
