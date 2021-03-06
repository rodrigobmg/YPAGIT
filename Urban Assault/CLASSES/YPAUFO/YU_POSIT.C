/*
**  $Source: $
**  $Revision: 38.1 $
**  $Date: 1995/06/12 18:24:47 $
**  $Locker: $
**  $Author: $
**
**
**
**  (C) Copyright 1995 by Andreas Flemming
*/
#include <exec/types.h>

#include <math.h>

#include "nucleus/nucleus2.h"
#include "engine/engine.h"
#include "transform/tform.h"
#include "ypa/ypaworldclass.h"
#include "ypa/ypabactclass.h"
#include "input/input.h"
#include "ypa/ypaufoclass.h"


/*-----------------------------------------------------------------*/
_extern_use_nucleus
_extern_use_tform_engine


_dispatcher(BOOL, yu_YBM_SETPOSITION, struct setposition_msg *setpos)
{
    /*
    ** FUNCTION:    Setzt ein Objekt auf eine Position. Dabei sehen wir nach, ob
    **              es schon in einer BactList ist, nehmen es dort raus, klinken
    **              es in die neue Liste ein und setzen den Sektorpointer.
    **              Evtl. wird das Objekt, wenn es gew�nscht ist, noch auf
    **              Bodenh�he gesetzt.
    **
    ** RESULTS      TRUE, wenn die Position ok war, sonst FALSE
    **
    ** CHANGES      24.9.95 kri�ted af
    **
    */

    struct ypaufo_data *yud;

    yud = INST_DATA( cl, o );

    /*** erstmal nach oben weitergeben ***/
    if( !_supermethoda( cl, o, YBM_SETPOSITION, setpos))  return( FALSE );

    /*** Auftrieb ***/
    yud->buoyancy = yud->bact->mass * GRAVITY;

    return( TRUE );

}


