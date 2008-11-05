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
#include <string>
#include <iomanip>

using namespace ::std;

int main()
{
    // output
    int i = 123; 
    string s = "abc";

    /* // case 1
    cout << s;
	// p. 23 {{{
    cout << endl;
    cout << setw(10);
	}}}
    cout << i;
    /*/ // case 2:
    cout << s;
	// p. 23 {{{
    cout << '\n'; cout.flush();
    cout.width(10);
	// }}}
    cout << i;
    //*/

    return 0;
}

/* Output case 1:
abc
       123
*/
/* Output case 2:
abc
       123
*/
