/*
author:  "Klaus Wittlich" <Klaus_Wittlich@sae.de> 

Based on source code published in the book "Standard C++ IOStreams 
and Locales" by Angelika Langer & Klaus Kreft, Copyright (c) 2000 by 
Addison Wesley Longman, Inc.

Permission to use, copy, and modify this software for any non-profit
purpose is hereby granted without fee.  Neither the author of this 
source code, Klaus Wittlich, nor the authors of the above mentioned 
book, Angelika Langer and Klaus Kreft, nor the publisher, Addison Wesley 
Longman, Inc., make any representations about the suitability of this 
software for any purpose.  It is provided "as is" without express or 
implied warranty.
*/

#include <ios>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cassert>

using namespace ::std;

// p. 74 {{{
template <class Stream>
void streamcpy(Stream& dest, const Stream& src)
{
    // clear exception mask
    dest.exceptions(ios_base::goodbit);

    dest.clear(src.rdstate() );

    typedef basic_ios<  Stream::char_type
                      , Stream::traits_type> StreamBase;
    (static_cast<StreamBase&>(dest) )
        .rdbuf( (static_cast<const StreamBase&>(src) ).rdbuf() );
    // call copyfmt after all other actions because it copies
    // the exception mask, which might result in any exceptions thrown
    dest.copyfmt(src);
}
// }}}

int main()
{
	// p. 74 {{{
    ostringstream o2, o1;
    streamcpy(o1, o2);
    o1 << "... something...";
	// }}}
	// p. 75 {{{
    o2 << "---- something else ----";
    cout << o1.str();       // prints nothing
	// {{{
    assert(o1.str() == ""); // prove really nothing was printed
	// }}}
    cout << o2.str();       // prints the combined output

	ofstream log("log.txt");

    streamcpy(cerr, static_cast<ostream&>(log) ); // Original

    cerr << "+++++" << endl; // !!! +++++ is easyier to see than " ... ". All chars are visible
	// }}}

    return 0;
}

/* Input: No input
*/
/* Output: Screen:
... something...---- something else ----
*/
/* Output: log.txt
+++++
*/
/* Other observable effects: Access violation
*/