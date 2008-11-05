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

// Annotation:
// If files src.cpp and dst.cpp do not exist, src.cpp is created but dst.cpp not.
// If files src.cpp and dst.cpp exist, src.cpp is cleared ans dst.cpp remains untouched.

#include <fstream>
#include <iostream>

using namespace ::std;

int main()
{
	// p. 41 {{{
    ofstream fil("src.cpp"); // file stream is connected to "src.cpp"

    fil.open("dst.cpp");     // attempt to connect to another file; will fail
    if (fil.fail() )
    {
		/* open operation failed */
		// }}}
        cerr << "open operation failed" << endl;
		// p. 41 {{{
    }

    if (fil.is_open() )
    {
        cerr << "connected to an open file, namely \"src.cpp\"" << endl; // !!!
    }
	// }}}

    return 0;
}

/* Output: 
open operation failed
connected to anopen file, namely "src.cpp"
*/
