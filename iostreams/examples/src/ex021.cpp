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
	// p. 21 {{{
    // input
    int i; string s;

    cin.width(10); 
    cin >> i >> s;
	// }}}

    assert( 12345 == i );
    assert( s == "abcdefghij");

    return 0;
}

/* Input: (Press enter after input)
12345 abcdefghijklmnopqrstuvwxyz
*/
