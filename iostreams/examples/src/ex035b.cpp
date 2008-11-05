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
    int x = 123;

    /* // case 1:
	// p. 35 {{{
    cout << x;
    if ( cout.good() )
	// }}}
    /*/ // case 2:
	// p. 35 {{{
    if ( cout << x, cout.good() )
    // }}}
    //*/
        cout << " x << with success" << endl;

    return 0;
}

/* Output case 1:
123 x << with success
*/
/* Output case 2:
123 x << with success
*/