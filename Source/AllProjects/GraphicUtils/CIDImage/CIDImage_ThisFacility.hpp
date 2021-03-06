//
// FILE NAME: CIDImage_ThisFacility.hpp
//
// AUTHOR: Dean Roddey
//
// CREATED: 12/27/1997
//
// COPYRIGHT: $_CIDLib_CopyRight_$
//
//  $_CIDLib_CopyRight2_$
//
// DESCRIPTION:
//
//  This is the header for the CIDImage_ThisFacility.cpp file. This file
//  implements the facility class for this facility.
//
// CAVEATS/GOTCHAS:
//
// LOG:
//
//  $_CIDLib_Log_$
//
#pragma once


#pragma CIDLIB_PACK(CIDLIBPACK)


// ---------------------------------------------------------------------------
//  CLASS: TFacCIDImage
// PREFIX: fac
// ---------------------------------------------------------------------------
class CIDIMGEXP TFacCIDImage : public TFacility
{
    public  :
        // -------------------------------------------------------------------
        //  Constructors and Destructor
        // -------------------------------------------------------------------
        TFacCIDImage();

        ~TFacCIDImage();


    private :
        // -------------------------------------------------------------------
        //  Do any needed magic macros
        // -------------------------------------------------------------------
        RTTIDefs(TFacCIDImage,TFacility)
};

#pragma CIDLIB_POPPACK


