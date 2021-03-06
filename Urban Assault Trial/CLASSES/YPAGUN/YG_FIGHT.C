/*
**  $Source: PRG:MovingCubesII/Classes/_YPABactClass/yb_attrs.c,v $
**  $Revision: 38.1 $
**  $Date: 1995/06/12 18:22:59 $
**  $Locker: floh $
**  $Author: floh $
**
**  Attribut-Handling f�r ypacar.class.
**
**  (C) Copyright 1995 by Andreas Flemming
*/
#include <exec/types.h>
#include <exec/lists.h>
#include <exec/nodes.h>
#include <exec/memory.h>

#include <utility/tagitem.h>

#include <math.h>

#include "nucleus/nucleus2.h"
#include "nucleus/math.h"
#include "engine/engine.h"
#include "ypa/ypaworldclass.h"
#include "ypa/ypabactclass.h"
#include "ypa/ypagunclass.h"
#include "ypa/ypamissileclass.h"

/*-----------------------------------------------------------------*/
_extern_use_nucleus
_extern_use_tform_engine


_dispatcher( void, yg_YBM_FIGHTBACT, struct fight_msg *fight )
{
/*
**  FUNCTION    Realiziert das Schie�en auf das Ziel je nach gew�nschter
**              Art und Weise
**
**  INPUT       Zeiten und das Ziel selbst
**
**  RESULT      n�scht
**
**  CHANGED     21-Jan-96       8100 000C created
*/

    struct ypagun_data *ygd;
    struct firemissile_msg fire;
    struct setstate_msg state;
    struct flt_triple richtung;
    FLOAT  distance;
    struct fireyourguns_msg fyg;

    ygd = INST_DATA( cl, o);

    richtung.x = fight->enemy.bact->pos.x - ygd->bact->pos.x;
    richtung.y = fight->enemy.bact->pos.y - ygd->bact->pos.y;
    richtung.z = fight->enemy.bact->pos.z - ygd->bact->pos.z;

    distance = nc_sqrt( richtung.x * richtung.x + richtung.y * richtung.y +
                        richtung.z * richtung.z );

    if( distance < 0.001 ) return;

    richtung.x /= distance;
    richtung.y /= distance;
    richtung.z /= distance;

    /*** Sind wir au�erhalb der Schu�position? (bei Guns ist Entf. gr��er!) ***/
    if( (distance > 2 * SECTOR_SIZE) ||
        ( 0.95 > richtung.x * ygd->bact->dir.m31 + richtung.y * ygd->bact->dir.m32 +
                 richtung.z * ygd->bact->dir.m33 ) ) {

        /*** Evtl VisProto �ndern ***/
        if( ygd->firetype == GF_Proto ) {

            state.main_state = state.extra_on = 0;
            state.extra_off  = EXTRA_FIRE;
            _methoda( o, YBM_SETSTATE, &state );
            }

        /*** Und tsch��... ***/
        return;
        }


    /*** Nun die Arten h�chstselbst ***/
    switch( ygd->firetype ) {

        case GF_None:

            /*** Hm, n�scht ***/
            break;

        case GF_Real:

            /*** Wir schie�en mit Raketen ***/

            /*** Rakete abfeuern ***/
            fire.dir.x       = richtung.x; // ygd->bact->dir.m31;
            fire.dir.y       = richtung.y; // ygd->bact->dir.m32;
            fire.dir.z       = richtung.z; // ygd->bact->dir.m33;
            fire.start.x     = ygd->bact->firepos.x;
            fire.start.y     = ygd->bact->firepos.y;
            fire.start.z     = ygd->bact->firepos.z;
            fire.target_type = TARTYPE_BACTERIUM;
            fire.target.bact = fight->enemy.bact;
            fire.wtype       = ygd->bact->auto_ID;
            fire.global_time = fight->global_time;
            fire.flags       = 0;
            if( _methoda( o, YBM_FIREMISSILE, &fire ) ) {

                /* -----------------------------------------------------------
                ** F�r das "Buildings-Flag machen wir einen Hack: Ich hole
                ** mir die unterste Rakete, die diese ja sein mu�, und modifi-
                ** ziere sie nachtr�glich.
                ** ---------------------------------------------------------*/
                ULONG UI;

                _get( o, YBA_UserInput, &UI );
                if( !UI ) {

                    struct OBNode *waffe = (struct OBNode *)ygd->bact->auto_list.mlh_TailPred;
                    if( waffe->nd.mln_Succ ) {

                        /*** Flag setzen ***/
                        _set( waffe->o, YMA_IgnoreBuildings, TRUE );
                        }
                    }

                /*** Zeit setzen ***/
                ygd->firecount = ygd->firetime;

                /*** VisProto setzen ***/
                state.main_state = state.extra_off = 0;
                state.extra_on   = EXTRA_FIRE;
                _methoda( o, YBM_SETSTATE, &state );
                }

            break;

        case GF_Proto:

            /*** VisProto setzen ***/
            if( !(ygd->bact->ExtraState & EXTRA_FIRE ) ) {

                state.main_state = state.extra_off = 0;
                state.extra_on   = EXTRA_FIRE;
                _methoda( o, YBM_SETSTATE, &state );
                }

            /*** Energie abziehen ***/
            fyg.time        = fight->time;
            fyg.global_time = fight->global_time;
            fyg.dir.x       = ygd->bact->dir.m31;
            fyg.dir.y       = ygd->bact->dir.m32;
            fyg.dir.z       = ygd->bact->dir.m33;
            _methoda( o, YBM_FIREYOURGUNS, &fyg );

            break;
        }
}


_dispatcher( BOOL, yg_YBM_TESTSECTARGET, struct Bacterium *enemy )
{
/*
**  FUNCTION    Erste sinnvolle Verwendung (�berlagerung) der ansonsten
**              leeren Methode zum weiteren Untersuchen des (m�glichen)
**              Nebenzieles.
**              Hier werden wir die winkel, auf die sich die Kanone
**              drehen kann, und die Entfernung beachten.
**              logische Sachen, wie Owner, Zustand etc. wurden bereit
**              abgehandelt
**
**  RESULT      TRUE: Das Ziel ist ok f�r uns
**
**  INPUT       dr Feind
**
**  CHANGED     af Welt-Nichtraucher-Tag
*/

    struct ypagun_data *ygd;
    struct flt_triple tvec, ve, vn;
    FLOAT  angle, distance, lvn, dv;

    ygd = INST_DATA( cl, o );

    tvec.x = enemy->pos.x - ygd->bact->pos.x;
    tvec.y = enemy->pos.y - ygd->bact->pos.y;
    tvec.z = enemy->pos.z - ygd->bact->pos.z;
    distance = nc_sqrt( tvec.x * tvec.x + tvec.y * tvec.y + tvec.z * tvec.z );

    /*** In mir? dann feuern, trifft immer und l�st damit das Problem ***/
    if( distance < 1.0 ) return( TRUE );

    /*** Kommen wir so weit? ***/
    if( 2 * SECTOR_SIZE < distance )
        return( FALSE );

    /*** Kommen wir so hoch? (90� - Winkel zu -rot) ***/
    tvec.x /= distance;
    tvec.y /= distance;
    tvec.z /= distance;
    
    angle = nc_acos(-ygd->rot.x*tvec.x - ygd->rot.y*tvec.y - ygd->rot.z*tvec.z );
    if( (PI/2 - angle) > ygd->max_up )
        return( FALSE );

    /*** Kommen wir so ... so weit runter? ***/
    angle = nc_acos(ygd->rot.x*tvec.x + ygd->rot.y*tvec.y + ygd->rot.z*tvec.z );
    if( (PI/2 - angle) > ygd->max_down )
        return( FALSE );

    /*** Kommen wir soweit rum? (Dazu erstmal tvec in die Drehebene projizieren) ***/
    lvn = tvec.x * ygd->rot.x + tvec.y * ygd->rot.y + tvec.z * ygd->rot.z;
    vn.x = ygd->rot.x * lvn;
    vn.y = ygd->rot.y * lvn;
    vn.z = ygd->rot.z * lvn;
    ve.x = tvec.x - vn.x;
    ve.y = tvec.y - vn.y;
    ve.z = tvec.z - vn.z;

    dv = nc_sqrt( ve.x*ve.x + ve.y*ve.y + ve.z*ve.z);

    if( dv > 0.1 ) {

        angle = nc_acos( (ygd->basis.x * ve.x +
                          ygd->basis.y * ve.y +
                          ygd->basis.z * ve.z) / dv );

        if( angle > ygd->max_xz )
            return( FALSE );
        }

    /*** es scheint alles ok zu sein ***/
    return( TRUE );
}
