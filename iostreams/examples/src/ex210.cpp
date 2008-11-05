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

#include <fstream>
#include <string>
#include <iostream>
#include <ctime>
#include <locale>

using namespace ::std;

#include "ocdatestream_212.h"
#include "date_196.h"
#include "setfmt_helper_205.h"

int main()
{
	// p. 212 {{{
	ocdatestream <basic_fstream<char> > ostr("outfile.txt", ios_base::out,""); // !!! ,"" added
	ostr << setfmt("%B %d, %Y is a %A.")  << date(11,8,1999) << endl;
	// }}}

    return 0;
}

/* Input: No Input
*/
/* Output: (in file outfile.txt)
August 11, 1999 is a Wednesday.
*/