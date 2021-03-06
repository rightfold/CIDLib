//
// FILE NAME: CIDZLib_Compressor.hpp
//
// AUTHOR: Dean Roddey
//
// CREATED: 08/14/2004
//
// COPYRIGHT: $_CIDLib_CopyRight_$
//
//  $_CIDLib_CopyRight2_$
//
// DESCRIPTION:
//
//  This is the header file for the CIDZLib_Compressor.Cpp file. This file
//  implements the zlib compression and decompression algorithms, and keeps
//  all the associated state for that.
//
//  This guy works in terms of streams. A binary input stream provides input
//  for the process, and a binary output stream accepts the results.
//
// CAVEATS/GOTCHAS:
//
// LOG:
//
//  $_CIDLib_Log_$
//
#pragma once


#pragma CIDLIB_PACK(CIDLIBPACK)

class TZLibCompImpl;

// ---------------------------------------------------------------------------
//  CLASS: TZLibCompressor
// PREFIX: zlib
// ---------------------------------------------------------------------------
class CIDZLIBEXP TZLibCompressor : public TObject
{
    public :
        // -------------------------------------------------------------------
        //  Constructors and Destructor
        // -------------------------------------------------------------------
        TZLibCompressor();

        TZLibCompressor(const TZLibCompressor&) = delete;

        ~TZLibCompressor();


        // -------------------------------------------------------------------
        //  Public operators
        // -------------------------------------------------------------------
        TZLibCompressor& operator=(const TZLibCompressor&) = delete;


        // -------------------------------------------------------------------
        //  Public, non-virtual methods
        // -------------------------------------------------------------------
        tCIDLib::TCard4 c4Compress
        (
                    TBinInStream&           strmInput
            ,       TBinOutStream&          strmOutput
            , const tCIDLib::TCard4         c4MaxInput = kCIDLib::c4MaxCard
        );

        tCIDLib::TCard4 c4Decompress
        (
                    TBinInStream&           strmInput
            ,       TBinOutStream&          strmOutput
            , const tCIDLib::TCard4         c4MaxInput = kCIDLib::c4MaxCard
        );


    private :
        // -------------------------------------------------------------------
        //  Private data members
        //
        //  m_pzimplThis
        //      The actual code is all in an internal implementation class
        //      so that we don't have to expose lots of constants and whatnot.
        // -------------------------------------------------------------------
        TZLibCompImpl*  m_pzimplThis;


        // -------------------------------------------------------------------
        //  Do any needed magic macros
        // -------------------------------------------------------------------
        RTTIDefs(TZLibCompressor,TObject)
};

#pragma CIDLIB_POPPACK

