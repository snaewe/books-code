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
#include <ios>
#include <locale>

using namespace ::std;

#include "date_196.h"
#include "setfmt_helper_205.h"
#include "copyfmterr_206.h"

int main()
{
	// cout.imbue(locale("American_USA.1252"));
	
	// p. 207 {{{
	date d(11,8,1999);
	cout << setfmt("%x is in week %U of year %Y.");
	cout << d << endl; //**
	cerr << setfmt("%B %d, %Y was a %A.");
	cout.copyfmt(cerr);

	if (copyfmtErr(cout) != ios_base::goodbit)
	{
		// do the appropriate error handling 
		cerr << "Error occured during using copyftErr" << endl; // !!! New in example
	}

	cout << d << endl; // now using the date format taken from cerr
	// }}}

    return 0;
}

/* Input: No input
*/
/* Output:
08/11/99 is in week 32 of year 1999.
August 11, 1999 was a Wednesday.
*/