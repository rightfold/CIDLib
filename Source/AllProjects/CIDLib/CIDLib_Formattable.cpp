//
// FILE NAME: CIDLib_Formattable.cpp
//
// AUTHOR: Dean Roddey
//
// CREATED: 09/24/1996
//
// COPYRIGHT: $_CIDLib_CopyRight_$
//
//  $_CIDLib_CopyRight2_$
//
// DESCRIPTION:
//
//  This file provides the little bit of out of line implementation
//  needed for the MFormattable mixin class. Note that, we need to be able
//  to provide a null object for this class, which raises some issues since
//  this class is not directly constructable. So we just construct a TPoint
//  object which implements MFormattable. That will serve for our needs.
//  The outside world doesn't know what it is.
//
// CAVEATS/GOTCHAS:
//
// LOG:
//
//  $_CIDLib_Log_$
//


// ---------------------------------------------------------------------------
//  Facility specific includes
// ---------------------------------------------------------------------------
#include    "CIDLib_.hpp"


// ---------------------------------------------------------------------------
//  CLASS: MFormattable
// PREFIX: fmtbl
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
//  MFormattable: Public, static methods
// ---------------------------------------------------------------------------
MFormattable& MFormattable::Nul_MFormattable()
{
    //
    //  We have to have some real class for this, which derives from formattable
    //  so we use TPoint.
    //
    static TPoint* pfmtblNull = nullptr;
    if (!pfmtblNull)
    {
        TBaseLock lockInit;
        if (!pfmtblNull)
            TRawMem::pExchangePtr(&pfmtblNull, new TPoint);
    }
    return *pfmtblNull;
}

