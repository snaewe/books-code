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
#include <ctime>
#include <locale>

using namespace ::std;

#include "date_220.h"
#include "setfmt_helper_221.h"
#include "odatestream_218.h"

int main()
{
	// p. 221 {{{
	cout << "Hello world, this is the year " << setfmt("%Y") << date(1,1,2000) 
		<< endl;
	// }}}
	// p. 222 {{{
	odatestream<basic_ostream<char> > ods(cout);
	ods << "Hello world, this is the year " << setfmt("%Y") << date(1,1,2000) 
		<< endl;
	// }}}
    return 0;
}

/* Input: No input
*/
/* Output:
Hello world, this is the year 01/01/00
Hello world, this is the year 2000
*/