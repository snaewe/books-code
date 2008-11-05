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
#include <cassert>

using namespace ::std;

int main()
{
    // Note: In the book line_buffer_size == 100, here it is set to 10.
    // That makes it easier to see what happens during debugging 
	// p. 50 {{{
    const int line_buffer_size = 10; // !!! see Note above
    char buffer[line_buffer_size];

    cin.getline(buffer, line_buffer_size, '\n');
	// }}}
    assert(0 == strcmp("123456",buffer) );
    assert(!cin.fail() );

	// second trial
	// p. 50 {{{
    cin.getline(buffer, line_buffer_size, '\n');
	// }}}
    assert(0 == strcmp("123456789",buffer) );
    assert(cin.fail() ); // "1234567890" contains a trailing '\0', that is too big for the 10 - byte buffer.

    return 0;
}

/* Input:
123456
1234567890
*/
/* Output: No Output
*/