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
    /* // case 1:
	// p. 22 {{{
    cout.setf( ios_base::left, ios_base::adjustfield);
    cout << 813;
	// }}}
    /*/ // case 2:
	// p. 22 {{{
    cout << left << 813;
	// }}}
    //*/
    return 0;
}

/* Output case 1:
813
*/
/* Output case 2:
813
*/
