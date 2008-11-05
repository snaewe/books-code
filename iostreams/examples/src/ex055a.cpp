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

#include <fstream>

using namespace ::std;

int main()
{
    //*
	// p. 55 {{{
    ofstream ostr("fil");
    int i = 10;
    ostr << unitbuf;
    while(i--)
    {
        ostr << i;
    }
	// }}}
    /*/

	// p. 55 {{{
    ofstream ostr("fil");
    int i = 10;
    while(i--)
    {
        ostr <<i;
        ostr.flush();
    }
	// }}}
    //*/

    return 0;
}

/* Input: No input
*/
/* Output: file fil:
9876543210
*/