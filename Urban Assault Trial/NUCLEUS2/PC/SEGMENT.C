/*
**  $Source: PRG:VFM/Nucleus2/pc/segment.c,v $
**  $Revision: 38.1 $
**  $Date: 1994/12/31 22:13:26 $
**  $Locker:  $
**  $Author: floh $
**
**  Die Code-Segment-Routinen f�r "statisch gelinktes ANSI-Nucleus".
**
**  (C) Copyright 1994 by A.Weissflog
*/
#include <exec/types.h>
#include <exec/lists.h>
#include <exec/nodes.h>

#include "nucleus/nucleus2.h"    /* wegen Nucleus-Prototypes */
#include "nucleus/segment.h"

/*-------------------------------------------------------------------
**  Die interne Segmentliste hat hier ihren Header
*/
struct MinList SegmentList;

/*-----------------------------------------------------------------*/
void nc_AddSegment(struct SegInfo *seginfo)
/*
**  FUNCTION
**      Dieses nur f�r das statische Linkmodell g�ltige Routine
**      h�ngt ein Codesegment in die interne Segment-Liste. Das
**      hei�t nicht, das dieses Segment bereits allgemein
**      verf�gbar ist! Vielmehr erm�glicht es eine sehr primitve
**      "LoadSeg()"-Emulation, die eben nicht im Filesystem nach
**      dem Segment sucht, sondern in der internen Segment-Liste
**      (die bereits vor dem allerersten nc_OpenSegment() komplett
**      aufgebaut sein sollte, z.B. innerhalb nc_OpenNucleus()).
**
**      Bitte beachten, da� vor dem ersten nc_AddSegment() die
**      Segment-Liste initialisiert werden mu�, das passiert innerhalb
**      nc_SystemInit().
**
**  INPUTS
**      seginfo -> Pointer auf ausgef�llte SegInfo-Struktur:
**          seginfo->node.ln_Name -> Pointer auf Segment-Name
**          seginfo->entry        -> Pointer auf Einsprung-Punkt (mu�
**                                   Pointer auf Segment-GET zur�ckgeben).
**
**  RESULTS
**      ---
**
**  CHANGED
**      27-Dec-94   floh    created
*/
{
    /* Segment einklinken... */
    nc_AddTail((struct List *)&SegmentList, (struct Node *) seginfo);
};

/*-----------------------------------------------------------------*/
ULONG *nc_OpenSegment(UBYTE *name, struct SegmentHandle *seghandle)
/*
**  FUNCTION
**      Diese "ANSI-static-Version" durchsucht die interne SegmentListe
**      nach dem durch <name> definierten Code-Segment (das ist
**      praktisch eine LoadSeg()-Emulation), holt sich den Pointer
**      auf die Einsprung-Routine, springt diese an und f�llt mit
**      den erhaltenen Informationen das �bergebene SegmentHandle aus.
**
**  INPUTS
**      name      -> Filename des zu ladeneden Segments (CASE SENSITIV!!!!!)
**      seghandle -> extern bereitgestellte SegmentHandle-Struktur,
**                   die ausgef�llt wird (wird von nc_CloseSegment()
**                   ben�tigt).
**  RESULTS
**      ULONG * -> Pointer auf Segment-Typ-spezifische Global Entry Table
**                 (<struct GET_Class> oder <struct GET_Engine>), oder
**                 NULL, falls Segment nicht gefunden.
**
**  CHANGED
**      27-Dec-94   floh    created
*/
{
    struct SegInfo *seginfo;
    ULONG *get;

    /* suche Code-Segment in interner Segment-Liste */
    seginfo = (struct SegInfo *) nc_FindName((struct List *)&SegmentList,name);
    if (!seginfo) return(NULL);

    /* springe Entry-Point an */
    get = seginfo->entry();
    if (!get) return(NULL);

    /* f�lle SegmentHandle aus */
    seghandle->seginfo = seginfo;
    seghandle->GET     = get;

    /* fertig */
    return(get);
};

/*-----------------------------------------------------------------*/
void nc_CloseSegment(struct SegmentHandle *seghandle)
/*
**  FUNCTION
**      Weil eh alles statisch ist, ist diese Routine leer.
**
**  INPUTS
**      seghandle   -> Pointer auf SegmentHandle, wie von
**                     nc_OpenSegment() ausgef�llt.
**
**  RESULTS
**      ---
**
**  CHANGED
**      27-Dec-94   floh    created
*/
{ };

