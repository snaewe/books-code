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
#include <iostream>
#include <cassert>

using namespace ::std;

// p. 66 {{{
void foo(ios_base& str)
{
    int idx = str.xalloc();

    if (str.fail())  // In contradiction to book, this works!
					 // fail is member of ios_base. ios_base is
					 // implemented in <xiosbase>
	    // {{{
        assert(0);
		// }}}
}
// }}}

int main()
{
    foo(cout);

    return 0;
}

/* Input: No input
*/
/* Output: No output
*/