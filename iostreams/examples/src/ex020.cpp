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

using namespace ::std;

int main()
{
	// p. 20 {{{
    ios_base::fmtflags original_flags = cout.flags();

    cout << 812 <<'|';
    cout.setf(ios_base::left, ios_base::adjustfield);
    cout.width(10);
    cout << 813 << 815 << '\n';

    cout.unsetf(ios_base::adjustfield);
    streamsize original_precision = cout.precision(2);
    cout.setf(ios_base::uppercase | ios_base::scientific);
    cout << 831.0 << ' ' << 8e2;

    cout.flags(original_flags);
    cout.precision(original_precision);
	// }}}

    return 0;    
}

/* Output: 
812|813       815
8.31E+002 8.00E+002
*/
