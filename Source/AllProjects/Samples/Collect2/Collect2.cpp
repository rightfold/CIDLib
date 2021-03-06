//
// FILE NAME: Collect2.cpp
//
// AUTHOR: Dean Roddey
//
// CREATED: 07/24/1997
//
// COPYRIGHT: $_CIDLib_CopyRight_$
//
//  This file is part of a demonstration program of the CIDLib C++
//  Frameworks. Its contents are distributed 'as is', to provide guidance on
//  the use of the CIDLib system. However, these demos are not intended to
//  represent a full fledged applications. Any direct use of demo code in
//  user applications is at the user's discretion, and no warranties are
//  implied as to its correctness or applicability.
//
// DESCRIPTION:
//
//  This is the main module for the second of the collection oriented demo
//  programs. This one demonstrates the hash map collection. It creates a
//  simple class, TNameInfo, which is the element type for the test. This
//  class has a name string, the key field, and a counter. It is used to
//  track how many times a name is found in a list. A simple array of strings
//  is used as test data.
//
//  The logic of the program is to test to see if the next name is in the
//  set already. If not, its added. If so, then its counter is bumped up.
//  At the end, the information is dumped out.
//
//  The hash map requires a 'key ops' object to handle hashing and comparing
//  key objects. Since our key field is a TString, we can use a canned one
//  that is provided by CIDLib, TStringKeyOps. We also have to provide a
//  small function that will pull out the key from the data element.
//
//  This guy also demonstrates column text output using stream format objects.
//
//  As with most of these simple demos, this one does not create a facility
//  object, it just starts the main thread on a local function.
//
// CAVEATS/GOTCHAS:
//
// LOG:
//
//  $_CIDLib_Log_$
//


// ---------------------------------------------------------------------------
//  Includes.
// ---------------------------------------------------------------------------
#include    "CIDLib.hpp"


// ---------------------------------------------------------------------------
//  Local data
//
//  conOut
//      This is a console object which we use in this program for our standard
//      output. Its a specialized text stream class. We don't support
//      redirection in this program, so we can just use a console directly.
// ---------------------------------------------------------------------------
static TOutConsole  conOut;


// ---------------------------------------------------------------------------
//  Do the magic main module code
// ---------------------------------------------------------------------------
tCIDLib::EExitCodes eMainThreadFunc(TThread&, tCIDLib::TVoid*);
CIDLib_MainModule(TThread(L"Collect2MainThread", eMainThreadFunc))


// ---------------------------------------------------------------------------
//  Local, static data
//
//  apszNames
//      This is just a list of dummy names that serves as test data for the
//      program.
//
//  c4NameCount
//      The count of elements in the array. We use the tCIDLib::c4ArrayElems() macro
//      that does the usual calculation for us.
// ---------------------------------------------------------------------------
static const tCIDLib::TCh* apszNames[] =
{
    L"Habib, Amat"
    , L"Roddey, Dean"
    , L"Smith, John"
    , L"Wiedersatz, Michelle"
    , L"Heninger, Andy"
    , L"Werts, Michael"
    , L"Smith, John"
    , L"Clinton, Bill"
    , L"Clinton, Hillary"
    , L"Habib, Amat"
    , L"Smith, John"
    , L"Hendrix, Jimi"
    , L"Hahn, Jessie"
    , L"Joplin, Janis"
    , L"Hendrix, Jimi"
    , L"Smith, John"
};
static const tCIDLib::TCard4 c4NameCount = tCIDLib::c4ArrayElems(apszNames);


// ---------------------------------------------------------------------------
//   CLASS: TNameInfo
//  PREFIX: nmi
//
//  This is a small test class that is used as the element type for our
//  hash map.
// ---------------------------------------------------------------------------
class TNameInfo : public TObject
{
    public :
        // -------------------------------------------------------------------
        //  Constructors and Destructors
        // -------------------------------------------------------------------
        TNameInfo() :

            m_c4Counter(0)
        {
        }

        TNameInfo(const TString& strName) :

            m_c4Counter(1)
            , m_strName(strName)
        {
        }

        ~TNameInfo() {}


        // -------------------------------------------------------------------
        //  Public operators
        //
        //  The hash map requires equality operators for its elements
        // -------------------------------------------------------------------
        tCIDLib::TBoolean operator==(const TNameInfo& nmiSrc) const
        {
            if (&nmiSrc == this)
                return kCIDLib::True;

            return
            (
                (m_c4Counter == nmiSrc.m_c4Counter)
                &&  (m_strName == nmiSrc.m_strName)
            );
        }

        tCIDLib::TBoolean operator!=(const TNameInfo& nmiSrc) const
        {
            return !operator==(nmiSrc);
        }


        // -------------------------------------------------------------------
        //  Public, non-virtual methods
        // -------------------------------------------------------------------
        tCIDLib::TCard4 c4Counter() const
        {
            return m_c4Counter;
        }

        tCIDLib::TVoid IncCounter()
        {
            m_c4Counter++;
        }

        const TString& strName() const
        {
            return m_strName;
        }


    private :
        // -------------------------------------------------------------------
        //  Private data members
        // -------------------------------------------------------------------
        tCIDLib::TCard4     m_c4Counter;
        TString             m_strName;


        // -------------------------------------------------------------------
        //  Do any needed macro stuff
        // -------------------------------------------------------------------
        RTTIDefs(TNameInfo,TObject)
};
RTTIDecls(TNameInfo,TObject)


// ---------------------------------------------------------------------------
//  Create an alias for our hash map of TNameInfo object, with string
//  keys, and string key ops.
// ---------------------------------------------------------------------------
using TNameInfoList = TKeyedHashSet<TNameInfo,TString,TStringKeyOps>;


// ---------------------------------------------------------------------------
//  Local functions
// ---------------------------------------------------------------------------

// A simple key extractor for the keyed hash set
static const TString& strKey(const TNameInfo& nmiCur)
{
    return nmiCur.strName();
}


// This is the the thread function for the main thread.
tCIDLib::EExitCodes eMainThreadFunc(TThread& thrThis, tCIDLib::TVoid*)
{
    // We have to let our calling thread go first
    thrThis.Sync();

    try
    {
        // Create a hash map of name info objects., with a modulus of 11
        TNameInfoList colOfNames(11, new TStringKeyOps, strKey);

        //
        //  Loop through our list of names and create a name info object
        //  for each one we find. We test each one to see if its there, and
        //  add it if not. If it is already there, we bump its counter.
        //
        for (tCIDLib::TCard4 c4Index = 0; c4Index < c4NameCount; c4Index++)
        {
            // Find the existing element or add it if not already there
            tCIDLib::TBoolean bAdded;
            TNameInfo& nmiCur = colOfNames.objFindOrAdd(TString(apszNames[c4Index]), bAdded);

            // If we didn't just add it, then increment its counter
            if (!bAdded)
                nmiCur.IncCounter();
        }

        //
        //  Set up two stream format objects. One represents the name column
        //  and one represents the count column. We use these to control the
        //  output of each column.
        //
        TStreamFmt strmfCount(8, 0, tCIDLib::EHJustify::Right, kCIDLib::chSpace);
        TStreamFmt strmfName(48, 0, tCIDLib::EHJustify::Left, kCIDLib::chSpace);

        //
        //  Do a header line for the data we are going to dump out. Note
        //  that the TTextOutStream::Spaces() thingie outputs 4 spaces, which
        //  are not affected by the formatting. I.e. it will just output
        //  4 spaces, regardless of the set field width. We use this to
        //  space the columns apart. The same applies to the NewLn values
        //  which are not affected by formatting.
        //
        //  ESpaces() is built upon the more generic TTextOutStream::RepChars
        //  mechanism, which is a way to output a repeated sequence of
        //  characters.
        //
        const tCIDLib::TCard4 c4Spacing{4};
        conOut  << kCIDLib::NewLn << strmfCount << L"Count"
                << TTextOutStream::Spaces(c4Spacing)
                << strmfName << L"Name" << kCIDLib::NewLn
                << strmfCount << L"------"
                << TTextOutStream::Spaces(c4Spacing)
                << strmfName << L"---------------------"
                << kCIDLib::EndLn;

        // Now iterate all the elements and dump their info out
        TNameInfoList::TCursor cursNames(&colOfNames);
        for (; cursNames; ++cursNames)
        {
            conOut  << strmfCount << cursNames->c4Counter()
                    << TTextOutStream::Spaces(c4Spacing)
                    << strmfName << cursNames->strName()
                    << kCIDLib::EndLn;
        }
    }

    // Catch any CIDLib runtime errors
    catch(const TError& errToCatch)
    {
        conOut  <<  L"A CIDLib runtime error occured during processing."
                << kCIDLib::NewLn <<  L"Error: " << errToCatch.strErrText()
                << kCIDLib::NewLn << kCIDLib::EndLn;
        return tCIDLib::EExitCodes::RuntimeError;
    }

    //
    //  Kernel errors should never propogate out of CIDLib, but I test
    //  for them in my demo programs so I can catch them if they do
    //  and fix them.
    //
    catch(const TKrnlError& kerrToCatch)
    {
        conOut  << L"A kernel error occured during processing.\nError="
                << kerrToCatch.errcId() << kCIDLib::NewLn << kCIDLib::EndLn;
        return tCIDLib::EExitCodes::FatalError;
    }

    // Catch a general exception
    catch(...)
    {
        conOut  << L"A general exception occured during processing"
                << kCIDLib::NewLn << kCIDLib::EndLn;
        return tCIDLib::EExitCodes::SystemException;
    }
    return tCIDLib::EExitCodes::Normal;
}
