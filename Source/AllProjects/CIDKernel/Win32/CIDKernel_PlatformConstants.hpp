//
// FILE NAME: CIDKernel_PlatformConstants.hpp
//
// AUTHOR: Dean Roddey
//
// CREATED: 09/12/1998
//
// COPYRIGHT: $_CIDLib_CopyRight_$
//
//  $_CIDLib_CopyRight2_$
//
// DESCRIPTION:
//
//  This file provides the platform dependent constants of the kCIDLib
//  namespace. It is the platform dependent sibling of the file
//  CIDKernel_Constant.hpp, which has all of the platform independent core
//  constants.
//
// CAVEATS/GOTCHAS:
//
// LOG:
//
//  $_CIDLib_Log_$
//
#pragma once


namespace kCIDLib
{
    // -----------------------------------------------------------------------
    //  File system constants
    // -----------------------------------------------------------------------
    const tCIDLib::TCard4           c4MaxPathLen    = 260;
    const tCIDLib::TCh* const       pszAllFilesSpec = L"*";
    const tCIDLib::TCh* const       pszAllDirsSpec  = L"*";
    const tCIDLib::TCh* const       szWhitespace    = L"\r\n\t\a\f\v ";
    const tCIDLib::TCh* const       szExeExtension  = L".Exe";
    const tCIDLib::TCh* const       szLibExtension  = L".DLL";
    const tCIDLib::TCh              chMultiPathSep  = L';';
    const tCIDLib::TCh* const       szMultiPathSep  = L";";
    const tCIDLib::TCh              chPathSep       = L'\\';
    const tCIDLib::TCh* const       szSysExePath    = L"PATH";
    const tCIDLib::TCh* const       szSysLibPath    = L"PATH";


    // -----------------------------------------------------------------------
    //  Memory related constants
    // -----------------------------------------------------------------------
    const tCIDLib::TCard4           c4MemPageSize   = 4096;


    // -----------------------------------------------------------------------
    //  Our native character encoding
    // -----------------------------------------------------------------------
    const tCIDLib::TCh* const       pszNativeEncoding = L"UTF-16LE";


    // -----------------------------------------------------------------------
    //  Process and thread related constants
    // -----------------------------------------------------------------------
    const tCIDLib::TProcessId       pidInvalid      = 0;
    const tCIDLib::TThreadId        tidInvalid      = 0;


    // -----------------------------------------------------------------------
    //  Character oriented constants. Here, we are responsible for the short
    //  and long char types. The Unicode char type is defined in a platform
    //  independent way.
    // -----------------------------------------------------------------------
    const tCIDLib::TCard4           c4SCharBytes    = 1;
    const tCIDLib::TSCh             schMaxSChar     = char(0x7F);
    const tCIDLib::TCard4           c4CharBytes     = 2;
    const tCIDLib::TCh              chMaxChar       = 0xFFFF;


    // -----------------------------------------------------------------------
    //  Max handles we can wait on at once. It's one less than the max so
    //  that we can have a slot for our own internal use.
    // -----------------------------------------------------------------------
    const tCIDLib::TCard4           c4MaxWaitHandles = 63;
}


namespace kCIDSock
{
    // -----------------------------------------------------------------------
    //  Socket related constants
    // -----------------------------------------------------------------------
    const tCIDLib::TCard4       c4MaxSelect     = 64;
}

namespace kCIDGraphDev
{

    // ------------------------------------------------------------------------
    //  These are the invalid values for some graphics oriented types
    // ------------------------------------------------------------------------
    const tCIDGraphDev::TBmpHandle      hbmpInvalid     = 0;
    const tCIDGraphDev::TBrushHandle    hbrInvalid      = 0;
    const tCIDGraphDev::TDeviceHandle   hdevInvalid     = 0;
    const tCIDGraphDev::TFontHandle     hfontInvalid    = 0;
    const tCIDGraphDev::TIconHandle     hicoInvalid     = 0;
    const tCIDGraphDev::TPenHandle      hpenInvalid     = 0;
    const tCIDGraphDev::TRegionHandle   hrgnInvalid     = 0;
}


namespace kCIDCtrls
{
    // ------------------------------------------------------------------------
    //  Invalid handle values
    // ------------------------------------------------------------------------
    const tCIDCtrls::TAccelHandle       haccelInvalid   = 0;
    const tCIDCtrls::TMenuHandle        hmenuInvalid    = 0;
    const tCIDCtrls::TWndHandle         hwndInvalid     = 0;
    const tCIDCtrls::TTimerId           tmidInvalid     = 0;
    const tCIDCtrls::TWndId             widInvalid      = 0xFFFFFFFF;
}

