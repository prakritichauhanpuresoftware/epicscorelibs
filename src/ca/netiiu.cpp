/*************************************************************************\
* Copyright (c) 2002 The University of Chicago, as Operator of Argonne
*     National Laboratory.
* Copyright (c) 2002 The Regents of the University of California, as
*     Operator of Los Alamos National Laboratory.
* EPICS BASE Versions 3.13.7
* and higher are distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution. 
\*************************************************************************/

/*  $Id$
 *
 *                    L O S  A L A M O S
 *              Los Alamos National Laboratory
 *               Los Alamos, New Mexico 87545
 *
 *  Copyright, 1986, The Regents of the University of California.
 *
 *  Author: Jeff Hill
 */

#include <limits.h>
#include <float.h>

#define epicsAssertAuthor "Jeff Hill johill@lanl.gov"

#include "iocinf.h"
#include "cac.h"
#include "netiiu.h"

netiiu::~netiiu ()
{
}

bool netiiu::ca_v42_ok () const
{
    return false;
}

bool netiiu::ca_v41_ok () const
{
    return false;
}

void netiiu::writeRequest ( epicsGuard < epicsMutex > &, nciu &, 
                           unsigned, arrayElementCount, const void * )
{
    throw cacChannel::notConnected();
}

void netiiu::writeNotifyRequest ( epicsGuard < epicsMutex > &, 
    nciu &, netWriteNotifyIO &, unsigned, arrayElementCount, const void * )
{
    throw cacChannel::notConnected();
}

void netiiu::readNotifyRequest ( epicsGuard < epicsMutex > &, 
    nciu &, netReadNotifyIO &, unsigned, arrayElementCount )
{
    throw cacChannel::notConnected();
}

void netiiu::clearChannelRequest ( 
    epicsGuard < epicsMutex > &, ca_uint32_t, ca_uint32_t )
{
}

void netiiu::subscriptionRequest ( 
    epicsGuard < epicsMutex > &, nciu &, netSubscription & )
{
}

void netiiu::subscriptionCancelRequest ( 
    epicsGuard < epicsMutex > &, nciu &, netSubscription & )
{
}

void netiiu::subscriptionUpdateRequest ( 
    epicsGuard < epicsMutex > &, nciu &, netSubscription & )
{
}

void netiiu::hostName ( char *pBuf, unsigned bufLength ) const
{
    if ( bufLength ) {
        strncpy ( pBuf, this->pHostName (), bufLength );
        pBuf[bufLength - 1u] = '\0';
    }
}

const char * netiiu::pHostName () const
{
    return "<disconnected>";
}

osiSockAddr netiiu::getNetworkAddress () const
{
    osiSockAddr addr;
    addr.sa.sa_family = AF_UNSPEC;
    return addr;
}

void netiiu::flushRequest ( epicsGuard < epicsMutex > & )
{
}

bool netiiu::flushBlockThreshold ( epicsGuard < epicsMutex > & ) const
{
    return false;
}

void netiiu::flushRequestIfAboveEarlyThreshold ( epicsGuard < epicsMutex > & )
{
}

void netiiu::blockUntilSendBacklogIsReasonable 
    ( cacContextNotify &, epicsGuard < epicsMutex > & )
{
}

void netiiu::requestRecvProcessPostponedFlush ()
{
    return;
}

void netiiu::uninstallChan ( epicsGuard < epicsMutex > &, 
                            epicsGuard < epicsMutex > &, nciu & )
{
    throw cacChannel::notConnected();
}





