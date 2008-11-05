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

#include <iostream>

using namespace ::std;

int main()
{
    int x = 123;

	// p. 36 {{{
    try {
        cout.exceptions(ios_base::badbit | ios_base::failbit);
        cout << x;
        // do lots of other stream output
	// }}}
        for ( int i = 0; i<100; ++i ) cout << i;
	// p. 36 {{{
    }
    catch(...) 
    {
        if ( cout.bad() )
        {   // unrecoverable error
	// }}}
            cerr << "unrecoverable error has occured" << endl;
	// p. 37 {{{
            throw;
        }        
        else if (cout.fail() )
        {   // retry
	// }}}
            cout << x;
            for (int i=0; i<100; ++i) cout << i;
			// p. 37 {{{
            return 0; // !!! main returns int
			// }}}
        }
    }

    return 0;
}

/* Output:
1230123456789101112131415161718192021222324252627282930313233343536373839404142434445464748495
0515253545556575859606162636465666768697071727374757677787980818283848586878889909192939495969
79899
*/
