//
// FILE NAME: CIDNameSrv_CoreAdminImpl.hpp
//
// AUTHOR: Dean Roddey
//
// CREATED: 07/30/2001
//
// COPYRIGHT: $_CIDLib_CopyRight_$
//
//  $_CIDLib_CopyRight2_$
//
// DESCRIPTION:
//
//  This is the header for the CIDNameSrv_CoreAdminImpl.cpp file, which
//  implements the TCIDCoreAdminImpl class. This is our implementation of the
//  CIDOrbUC defined core admin remote protocol. It allows us to be controlled
//  by any management client that understands this protocol. Actually we
//  derive from a base imlementation class that can provide some of the
//  standard functionality for us, not directly from the IDL stub class.
//
// CAVEATS/GOTCHAS:
//
// LOG:
//
#pragma once


#pragma CIDLIB_PACK(CIDLIBPACK)

// ---------------------------------------------------------------------------
//   CLASS: TCIDCoreAdminImpl
//  PREFIX: orbs
// ---------------------------------------------------------------------------
class TCIDCoreAdminImpl : public TCIDCoreAdminBaseImpl
{
    public :
        // --------------------------------------------------------------------
        // Constructors and Destructor
        // --------------------------------------------------------------------
        TCIDCoreAdminImpl();

        TCIDCoreAdminImpl(const TCIDCoreAdminImpl&) = delete;

        ~TCIDCoreAdminImpl();


        // --------------------------------------------------------------------
        //  Public operators
        // --------------------------------------------------------------------
        TCIDCoreAdminImpl& operator=(const TCIDCoreAdminImpl&) = delete;


        // --------------------------------------------------------------------
        // Public, inherited methods
        // --------------------------------------------------------------------
        tCIDLib::TVoid AdminStop();


    protected :
        // --------------------------------------------------------------------
        //  Protected, inherited methods
        // --------------------------------------------------------------------
        tCIDLib::TVoid Initialize() override;

        tCIDLib::TVoid Terminate() override;


    private :
        // --------------------------------------------------------------------
        //  Magic macros
        // --------------------------------------------------------------------
        RTTIDefs(TCIDCoreAdminImpl,TCIDCoreAdminBaseImpl)
};

#pragma CIDLIB_POPPACK

