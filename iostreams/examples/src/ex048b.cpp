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

#include <sstream>
#include <iomanip>
#include <cassert>

using namespace ::std;

int main()
{
	// p. 48 {{{
    ostringstream oBuf;
    oBuf.imbue(locale("German_Germany"));
    oBuf << setprecision(2) << fixed;

    double DeutschMark = 19.99;
    string Amount;

    oBuf << DeutschMark << " DM";
    if ( oBuf ) 
	{ // !!!
        Amount = oBuf.str(); // Amount now contains: "19,99 DM"
        assert( Amount == "19,99 DM" ); // !!!
    } // !!!

	// }}}

    return 0;
}

/* Output: No output
*/