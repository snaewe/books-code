/*
author:  "Klaus Wittlich" <Klaus_Wittlich@sae.de> 

Based on source code published in the book "Standard C++ IOStreams 
and Locales" by Angelika Langer & Klaus Kreft, Copyright (c) 2000 by 
Addison Wesley Longman, Inc.

Permission to use, copy, and modify this software for any non-profit
purpose is hereby granted without fee.  Neither the author of this 
source code, Klaus Wittlich, nor the authors of the above mentioned 
book, Angelika Langer and Klaus Kreft, nor the publisher, Addison
Wesley Longman, Inc., make any representations about the suitability of this 
software for any purpose.  It is provided "as is" without express or 
implied warranty.
*/

#include <iostream>

using namespace ::std;

int main()
{
    ostream& str = cout;
    locale loc("German_Germany");

	// p. 78 {{{
    if (str.rdbuf() != 0) 
	{ // !!!
        str.rdbuf()->pubimbue(loc);
	// }}}
        str << "*"; // This is only a marker that the if -condition was fulfilled
    }

    str << 19.99 << '\t' << fixed << 1000000 << endl;

    return 0;
}

/* Input: No input
*/
/* Output: (Please note differences to Ex78a! )
*19.99  1000000
*/