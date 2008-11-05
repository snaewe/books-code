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
#include <string>
#include <cassert>

using namespace ::std;

int main()
{
	// p. 55 {{{
    ofstream ostr("fil");
    ifstream istr("fil");
    string s;
	// }}}
	// p. 56 {{{
    ostream* old_tie = istr.tie(&ostr);
    ostr << "Hello world\n";
    istr >> s;
    istr.tie(old_tie);
	// }}}

    assert(s == "Hello");

    return 0;
}

/* Input: No input
*/
/* Output: File "fil"
Hello world

*/