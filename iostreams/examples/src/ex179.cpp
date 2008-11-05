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

#include "width_179.h"
#include "mendl_180.h"

int main()
{
	// p. 179 {{{
    cout << width(5) << 0.1 << endl;
	// }}}
	// p. 180 {{{
    cout << mendl(5);
	// }}}
	// p. 179 {{{
    cout << width(5) << 0.1 << endl;
	// }}}

    return 0;
}

/* Input: No input
*/
/* Output:
  0.1





  0.1
*/