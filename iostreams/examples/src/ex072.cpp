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
#include <cassert>

using namespace ::std;

int main()
{
	// p. 72 {{{
    basic_filebuf<char> buf;
    buf.open("in.txt",ios_base::in);

    basic_ifstream<char> ifstr;             // ifstr by default contains a file buffer object
    ifstr.basic_ios<char>::rdbuf(&buf);     // here the file buffer pointer is replaced using the
                                            // hidden base class version of the rdbuf() function

    basic_streambuf<char> * bp1, * bp2;     // !!! for comparsion reasons bp1 ans bp2 instead of only bp
    bp1 = ifstr.rdbuf();                    // redefined rdbuf() returns pointer to contained, but // !!! bp1 instead of bp
                                            // unused buffer
    bp2 = ifstr.basic_ios<char>::rdbuf();   // base class version of the rdbuf() function returns // !!! bp2 instead of bp
                                            // pointer to  newly assigned and actually used file buffer
    // }}}
    assert(bp1 != bp2);

    return 0;
}

/* Input: File in.txt needs not necessaryly exist.
*/
/* Output: No output
*/