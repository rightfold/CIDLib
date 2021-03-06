//
// FILE NAME: CIDKernel_SafeCounter.Cpp
//
// AUTHOR: Dean Roddey
//
// CREATED: 11/11/1996
//
// COPYRIGHT: $_CIDLib_CopyRight_$
//
//  $_CIDLib_CopyRight2_$
//
// DESCRIPTION:
//
//  This file provides the platform independent implementations of the
//  TKrnlSafeInt4Counter and TKrnlSafeCardCounter classes, which are thread
//  safe counters.
//
//
// CAVEATS/GOTCHAS:
//
// LOG:
//
//  $_CIDLib_Log_$
//

// ---------------------------------------------------------------------------
//  Includes
// ---------------------------------------------------------------------------
#include    "CIDKernel_.hpp"


// ---------------------------------------------------------------------------
//   CLASS: TKrnlSafeInt4Counter
//  PREFIX: scnt
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
//  TKrnlSafeInt4Counter: Public, non-virtual methods
// ---------------------------------------------------------------------------
tCIDLib::TInt4 TKrnlSafeInt4Counter::i4SetValue(const tCIDLib::TInt4 i4ToSet)
{
    // Just use the exchange command
    return i4Exchange(i4ToSet);
}



// ---------------------------------------------------------------------------
//   CLASS: TKrnlSafeCard4Counter
//  PREFIX: scnt
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
//  TKrnlSafeCard4Counter: Public, non-virtual methods
// ---------------------------------------------------------------------------
tCIDLib::TCard4 TKrnlSafeCard4Counter::c4SetValue(const tCIDLib::TCard4 c4ToSet)
{
    // Just use the exchange command
    return c4Exchange(c4ToSet);
}
