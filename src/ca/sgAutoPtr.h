/*************************************************************************\
* Copyright (c) 2002 The University of Chicago, as Operator of Argonne
*     National Laboratory.
* Copyright (c) 2002 The Regents of the University of California, as
*     Operator of Los Alamos National Laboratory.
* EPICS BASE Versions 3.13.7
* and higher are distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution. 
\*************************************************************************/

/*  
 *  $Id$
 *
 *                              
 *                    L O S  A L A M O S
 *              Los Alamos National Laboratory
 *               Los Alamos, New Mexico 87545
 *                                  
 *  Copyright, 1986, The Regents of the University of California.
 *                                  
 *           
 *	Author Jeffrey O. Hill
 *	johill@lanl.gov
 *	505 665 1831
 */

#ifndef sgAutoPtrh
#define sgAutoPtrh

template < class T >
class sgAutoPtr {
public:
    sgAutoPtr ( epicsGuard < epicsMutex > &, 
        struct CASG &, tsDLList < syncGroupNotify > & );
    ~sgAutoPtr ();
    sgAutoPtr < T > & operator = ( T * );
    T * operator -> ();
    T & operator * ();
    T * get ();
    T * release ();
private:
    tsDLList < syncGroupNotify > & list;
    T * pNotify;
    struct CASG & sg;
    epicsGuard < epicsMutex > & guard;
};

template < class T >
inline sgAutoPtr < T > :: sgAutoPtr ( 
    epicsGuard < epicsMutex > & guardIn, 
    struct CASG & sgIn, tsDLList < syncGroupNotify > & listIn  ) : 
    list ( listIn ), pNotify ( 0 ), sg ( sgIn ), guard ( guardIn )
{
}

template < class T >
inline sgAutoPtr < T > :: ~sgAutoPtr () 
{
    if ( this->pNotify ) {
        list.remove ( *this->pNotify );
        pNotify->destroy ( this->guard, this->sg );
    }
}

template < class T >
inline sgAutoPtr < T > & sgAutoPtr < T > :: operator = ( T * pNotifyIn )
{
    if ( this->pNotify ) {
        list.remove ( *this->pNotify );
        pNotify->destroy ( this->guard, this->sg );
    }
    this->pNotify = pNotifyIn;
    list.add ( *this->pNotify );
    return *this;
}

template < class T >
inline T * sgAutoPtr < T > :: operator -> ()
{
    return this->pNotify;
}

template < class T >
inline T & sgAutoPtr < T > :: operator * ()
{
    assert ( this->pNotify );
    return * this->pNotify;
}

template < class T >
inline T * sgAutoPtr < T > :: release ()
{
    T * pTmp = this->pNotify;
    this->pNotify = 0;
    return pTmp;
}

template < class T >
inline T * sgAutoPtr < T > :: get ()
{
    return this->pNotify;
}

#endif // sgAutoPtrh
