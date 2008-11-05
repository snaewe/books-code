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
#include <cassert>

using namespace ::std;

int main()
{

	// p. 118 {{{
    istringstream buf("0123456789"); // !!! Filling the stream is done by initialization
	// {{{
	char c0, c1, c2, c3, c4, c5; // We need these variables for example rearons
	char c0_, c1_, c2_, c3_, c4_, c5_; // We need these variables for example rearons for comparsion
	// }}}
    // read input until a position of interest and memorize the position
	// {{{
	buf >> c0 >> c1 >> c2;  
	// }}}
    istringstream::pos_type p = buf.tellg();
    if (p != istringstream::pos_type(-1) )
    {
        // tellg() was successful
        // read further input
		// {{{
		buf >> c3 >> c4 >> c5;
		// }}}
    }
	// {{{
	// Testing: Did we get what we expect
	assert('0' == c0 && '1' == c1 && '2' == c2 && '3' == c3 && '4' == c4 && '5' == c5);
	// }}}
    // return to the point of interest
    buf.seekg(p);
	// {{{
	// Test: Did we get to point of interest with success?
	buf >> c3_ >> c4_ >> c5_;
	assert(c3 == c3_ && c4 == c4_ && c5 == c5_);
	// }}}

    // return to beginning of stream
    buf.seekg(0, ios_base::beg);
	// {{{
	// Test: Did we get to beginning with success?
	buf >> c0_ >> c1_ >> c2_;
	assert(c0 == c0_ && c1 == c1_ && c2 == c2_);
	// }}}
	// }}}

    return 0;
}

/* Input: No input
*/
/* Output: No output
*/

