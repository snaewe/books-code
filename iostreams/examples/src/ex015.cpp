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
#include <complex>
#include <string>

using namespace ::std;

int main()
{
	// p. 15 {{{
    cout << int(10) << '\n';
    cout << complex<float>(1.0,2.5) << '\n';
    cout << bool(false) <<'\n';
    cout << string("Hello world\n") << '\n';
    cout << "Hello world\n" << '\n';
	// }}}

    /* // If you are a daredevil, activate this line of code:
	// p. 15 {{{
    printf("%d %s \n","Hello world\n", 10);
	}}}
    //*/

    return 0;
}

/* Output: 
10
(1,2.5)
0
Hello world

Hello world

*/
/*
Running this program with daredevil's code causes an access violation
*/
