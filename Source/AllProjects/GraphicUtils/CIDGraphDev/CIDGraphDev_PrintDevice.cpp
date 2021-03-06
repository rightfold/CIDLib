//
// FILE NAME: CIDGraphDev_PrintDevice.cpp
//
// AUTHOR: Dean Roddey
//
// CREATED: 05/27/1997
//
// COPYRIGHT: $_CIDLib_CopyRight_$
//
//  $_CIDLib_CopyRight2_$
//
// DESCRIPTION:
//
//  This file implements the TGraphPrintDev class, which is a derivative of
//  the basic drawable device used for printed output.
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
#include    "CIDGraphDev_.hpp"


// ---------------------------------------------------------------------------
//  Do our RTTI macros
// ---------------------------------------------------------------------------
RTTIDecls(TGraphPrintDev,TGraphDrawDev)



// ---------------------------------------------------------------------------
//  CLASS: TGraphPrintDevice
// PREFIX: gdev
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
//  TGraphPrintDevice: Constructors and Destructor
// ---------------------------------------------------------------------------
TGraphPrintDev::TGraphPrintDev( const   TString&    strDriverName
                                , const TString&    strPrinterName)
{
    tCIDGraphDev::TDeviceHandle hdevTmp = ::CreateDCW
    (
        strDriverName.pszBuffer()
        , strPrinterName.pszBuffer()
        , 0
        , 0
    );

    if (hdevTmp == kCIDGraphDev::hdevInvalid)
    {
        TKrnlError::SetLastHostError(::GetLastError());
        facCIDGraphDev().ThrowKrnlErr
        (
            CID_FILE
            , CID_LINE
            , kGrDevErrs::errcDev_CreatePrintDev
            , TKrnlError::kerrLast()
            , tCIDLib::ESeverities::Failed
            , tCIDLib::EErrClasses::CantDo
            , strDriverName
            , strPrinterName
        );
    }

    // Set the handle
    SetHandle(hdevTmp, tCIDLib::EAdoptOpts::Adopt);
}

TGraphPrintDev::~TGraphPrintDev()
{
    if ((eAdopted() == tCIDLib::EAdoptOpts::Adopt)
    &&  (hdevThis() != kCIDGraphDev::hdevInvalid))
    {
        if (!::DeleteDC(hdevThis()))
        {
            TKrnlError::SetLastHostError(::GetLastError());
            facCIDGraphDev().ThrowKrnlErr
            (
                CID_FILE
                , CID_LINE
                , kGrDevErrs::errcDev_DestroyPrintDev
                , TKrnlError::kerrLast()
                , tCIDLib::ESeverities::Failed
                , tCIDLib::EErrClasses::CantDo
            );
        }
    }
}

