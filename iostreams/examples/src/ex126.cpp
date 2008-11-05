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
#include <algorithm>
#include <fstream>
#include <string>

using namespace ::std;


int main()
{
	// p. 126 {{{
    ifstream str("my_text_file");

    istream_iterator<string> beginIter(str);
    istream_iterator<string> endIter;

    cout << "numeber of _the_: " << count(beginIter, endIter, "the");
	// }}}

    return 0;
}

/* Input: my_text_file
there is an example to count the "the"s. Please note that the file begins and end with a 
the

*/
/* Output:
numeber of _the_: 3
*/