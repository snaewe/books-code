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
#include <string>
#include <cassert>

using namespace ::std;



int main()
{
	// p. 50 {{{
    string buffer;

    getline(cin, buffer, '\n');
	// }}}
    assert(buffer == "123456");
    assert(!cin.fail() );

	// trial for second input
	// p. 50 {{{
    getline(cin, buffer, '\n');
	// }}}
    assert(buffer == "1234567890");
    assert(!cin.fail() );

    return 0;
}

/* Input:
123456
1234567890
*/
/* Output: No output
*/