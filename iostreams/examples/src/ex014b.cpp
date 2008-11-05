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
    /* // Hint: test both int x and void * x
    int x = 10;
    /*/
    void * x = 0;
    //*/

    /* // case 1
	// p. 14 {{{
    cout << "result: " << x;
	// }}}
    /*/
    // case 2
	// p. 14 {{{
    operator<<(cout,"result: ").operator<<(x);
	// }}}
    //*/
    return 0;
}

/* Output: int x, case 1:
result: 10
*/
/* Output: int x, case 2:
result: 10
*/
/* Output: void * x, case 1:
result: 00000000
*/
/* Output: void * x, case 2:
result: 00000000
*/