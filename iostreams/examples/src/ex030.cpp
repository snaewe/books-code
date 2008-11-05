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
#include <iomanip>
#include <cassert>

using namespace ::std;

int main()
{
    const int SZ = 10;

	{
		// p. 30 {{{
		// extracton of C string
		char buf[SZ];
		cin >> buf;
		// }}}

		assert(0 == strcmp("abcde", buf) );
	}

	{
		// p. 30
		// extracton of ++ string
		string s;
		cin >> s;
		// }}}
		assert("ABCDE" == s);
	}

	{
		// p. 31 {{{
		char buf[SZ];
		cin >> setw(SZ) >> buf;
		// }}}
		assert( 0 == strcmp("abcdefghi", buf) );
	}

    return 0;
}

/* Input:
abcde
ABCDE
abcdefghijklmnopqrstuvwxyz
*/
