//
// FILE NAME: CIDKernel_CriticalSection_Win32.Cpp
//
// AUTHOR: Will Mason
//
// CREATED: 12/09/1998
//
// COPYRIGHT: $_CIDLib_CopyRight_$
//
//  $_CIDLib_CopyRight2_$
//
// DESCRIPTION:
//
//  This file the Linux specific implementation of the TKrnlCritSec class.
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
#include    "CIDKernel_.hpp"
#include    "CIDKernel_InternalHelpers_.hpp"

// ---------------------------------------------------------------------------
//   CLASS: TKrnlCritSec
//  PREFIX: kcrs
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
//  TKrnlCritSec: Constructors and Destructor
// ---------------------------------------------------------------------------
TKrnlCritSec::TKrnlCritSec() :
    __pData(0)
{
    TKrnlLinux::TRecursiveMutex* prmtxThis =
        new TKrnlLinux::TRecursiveMutex();
    prmtxThis->iInitialize();
    __pData = prmtxThis;
}

TKrnlCritSec::~TKrnlCritSec()
{
    TKrnlLinux::TRecursiveMutex* prmtxThis =
        static_cast<TKrnlLinux::TRecursiveMutex*>(__pData);
    prmtxThis->iDestroy();
    delete prmtxThis;
}


// ---------------------------------------------------------------------------
//  TKrnlCritSec: Public, non-virtual methods
// ---------------------------------------------------------------------------
tCIDLib::TVoid TKrnlCritSec::Enter() const
{
    TKrnlLinux::TRecursiveMutex* prmtxThis =
        static_cast<TKrnlLinux::TRecursiveMutex*>(__pData);
    prmtxThis->iLock();
}


tCIDLib::TVoid TKrnlCritSec::Exit() const
{
    TKrnlLinux::TRecursiveMutex* prmtxThis =
        static_cast<TKrnlLinux::TRecursiveMutex*>(__pData);
    prmtxThis->iUnlock();
}
