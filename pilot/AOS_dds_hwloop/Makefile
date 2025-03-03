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

LIBS = -l"OpenDDS_Rtps_Udp" -l"OpenDDS_Rtps" -l"OpenDDS_InfoRepoDiscovery" -l"OpenDDS_Tcp" -l"OpenDDS_Dcps" -l"TAO_BiDirGIOP" -l"TAO_PI" -l"TAO_CodecFactory" -l"TAO_Valuetype" -l"TAO_PortableServer" -l"TAO_AnyTypeCode" -l"TAO" -l"ACE" -ldl $(subst lib,-l,$(sort $(basename $(notdir $(wildcard /usr/lib/librt.so /lib/librt.so))))) -lpthread

PKGSUBDIRS  = ${SHIPSUBDIRS}
src-robots-AOS_dds_hwloop_PKGFILES = $(shell find * -maxdepth 0 -type f -print)
src-robots-AOS_dds_hwloop_PKGDIR   = ${PACKAGE}-${VERSION}/$(subst ${TORCS_BASE},,$(shell pwd))

include ${MAKE_DEFAULT}
