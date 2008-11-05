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

#include <ctime>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <locale>

using namespace ::std;

#include "date_161.h"


int main()
{
    // 1st example page 168
    {
		// p. 168 {{{
        date eclipse(11, 8, 1999);
        cout << "eclipse (default right adjustment): " << setw(10)
            << setfill('(') << eclipse << endl;
        cout << "eclipse (left adjustment)           : " << left << setw(10)
            << setfill('*') << eclipse << endl;
        
        cout << "A date like Dec 2, 1978 is needed: ";
		// }}}
    }

    // 2nd example page 168
    {
		// p. 168 {{{
        date d;
        cin >> d;
        cout << "This is the specified date in US notation: " << d << endl;
        cout.imbue(locale("German"));
        cout << "This is the specified date in German notation: " << d << endl;
		// }}}
    }

    // example page 169
	for (int i=0; i<2; ++i)
	{
		try
		{
			// p. 169 {{{
			cout << "A date like Dec 2, 1978 is needed: ";
			date d;
			cin.exceptions(ios_base::badbit | ios_base::failbit);
			try { cin >> d; }
			catch (ios_base::failure&)
			{
				cerr << "date extraction failed" << endl;
				throw;
			}
			cout << "This is the specified date in US notation: " << d << endl;
			// }}}
		}
		catch(...) {}
	}

    return 0;
}

/* Input:
Dec 31, 1999
Dec 31, 1999
Dec 32, 1999
*/
/* Output:
eclipse (default right adjustment): ((08/11/99
eclipse (left adjustment)           : 08/11/99**
A date like Dec 2, 1978 is needed: 
This is the specified date in US notation: 12/31/99
This is the specified date in German notation: 31.12.99
A date like Dec 2, 1978 is needed: 
This is the specified date in US notation: 31.12.99
A date like Dec 2, 1978 is needed: 
date extraction failed
*/
/* Screen shot:
eclipse (default right adjustment): ((08/11/99
eclipse (left adjustment)           : 08/11/99**
A date like Dec 2, 1978 is needed: Dec 31, 1999
This is the specified date in US notation: 12/31/99
This is the specified date in German notation: 31.12.99
A date like Dec 2, 1978 is needed: Dec 31, 1999
This is the specified date in US notation: 31.12.99
A date like Dec 2, 1978 is needed: Dec 32, 1999
date extraction failed
*/