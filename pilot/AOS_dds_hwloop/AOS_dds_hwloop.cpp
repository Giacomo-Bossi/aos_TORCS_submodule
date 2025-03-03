/***************************************************************************

    file                 : AOS_dds_hwloop.cpp
    created              : Sun Feb 23 15:13:29 UTC 2025
    copyright            : (C) 2002 Apollonio Bossi

 ***************************************************************************/

#ifdef _WIN32
#include <windows.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <tgf.h>
#include <track.h>
#include <car.h>
#include <raceman.h>
#include <robottools.h>
#include <robot.h>

// Let's see if it will work
#include <dds/DCPS/Marked_Default_Qos.h>
#include <dds/DCPS/Service_Participant.h>
#include <dds/DCPS/WaitSet.h>
#include <dds/DCPS/StaticIncludes.h>
#if OPENDDS_DO_MANUAL_STATIC_INCLUDES
#include <dds/DCPS/RTPS/RtpsDiscovery.h>
#include <dds/DCPS/transport/rtps_udp/RtpsUdp.h>
#endif

#include <dds/DdsDcpsInfrastructureC.h>
#include <dds/DdsDcpsPublicationC.h>

// #include <ace/Log_Msg.h>

static tTrack *curTrack;

static void initTrack(int index, tTrack *track, void *carHandle, void **carParmHandle, tSituation *s);
static void newrace(int index, tCarElt *car, tSituation *s);
static void drive(int index, tCarElt *car, tSituation *s);
static void endrace(int index, tCarElt *car, tSituation *s);
static void shutdown(int index);
static int InitFuncPt(int index, void *pt);

/*
 * Module entry point
 */
extern "C" int
AOS_dds_hwloop(tModInfo *modInfo)
{
    memset(modInfo, 0, 10 * sizeof(tModInfo));

    modInfo->name = strdup("AOS_dds_hwloop"); /* name of the module (short) */
    modInfo->desc = strdup("");               /* description of the module (can be long) */
    modInfo->fctInit = InitFuncPt;            /* init function */
    modInfo->gfId = ROB_IDENT;                /* supported framework version */
    modInfo->index = 1;

    return 0;
}

/* Module interface initialization. */
static int
InitFuncPt(int index, void *pt)
{
    tRobotItf *itf = (tRobotItf *)pt;

    itf->rbNewTrack = initTrack; /* Give the robot the track view called */
                                 /* for every track change or new race */
    itf->rbNewRace = newrace;    /* Start a new race */
    itf->rbDrive = drive;        /* Drive during race */
    itf->rbPitCmd = NULL;
    itf->rbEndRace = endrace;   /* End of the current race */
    itf->rbShutdown = shutdown; /* Called before the module is unloaded */
    itf->index = index;         /* Index used if multiple interfaces */
    return 0;
}

/* Called for every track change or new race. */
static void
initTrack(int index, tTrack *track, void *carHandle, void **carParmHandle, tSituation *s)
{
    curTrack = track;
    *carParmHandle = NULL;
}

/* Start a new race. */
static void
newrace(int index, tCarElt *car, tSituation *s)
{
}

/* Drive during race. */
static void
drive(int index, tCarElt *car, tSituation *s)
{
    memset((void *)&car->ctrl, 0, sizeof(tCarCtrl));
    /*
     * add the driving code here to modify the
     * car->_steerCmd
     * car->_accelCmd
     * car->_brakeCmd
     * car->_gearCmd
     * car->_clutchCmd
     */
    float angle = RtTrackSideTgAngleL(&(car->_trkPos)) - car->_yaw;
    angle = remainder(angle, 2 * PI); // making sure angle is within -PI and PI
    angle -= car->_trkPos.toMiddle / car->_trkPos.seg->width;

    car->_steerCmd = angle / car->_steerLock;
    car->_gearCmd = 1;    // first gear
    car->_accelCmd = 0.3; // 30% acceleration
    car->_brakeCmd = 0.0; // no brakes
}

/* End of the current race */
static void
endrace(int index, tCarElt *car, tSituation *s)
{
}

/* Called before the module is unloaded */
static void
shutdown(int index)
{
}
