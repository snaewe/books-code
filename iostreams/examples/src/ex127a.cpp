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

#include <list>
#include <algorithm>
#include <iostream>

using namespace ::std;

int main()
{
	// p. 127 {{{
    list<int> myList;

    // fill in some elements
	// {{{
    int pi[26] = { 3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6,2,6,4,3,3};
    myList.insert(myList.begin(), pi,pi+26);
	// }}}

    copy(myList.begin(), myList.end(), ostream_iterator<int>(cout, " ") );
	// }}}

    return 0;
}

/* Input: No input
*/
/* Output:
3 1 4 1 5 9 2 6 5 3 5 8 9 7 9 3 2 3 8 4 6 2 6 4 3 3
*/