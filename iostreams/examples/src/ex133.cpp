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
#include <algorithm>

using namespace ::std;

// In Mcrosoft Visual C++.Net string::iterator is not a pointer. So we need 
// an operator << for string::iterator.
// Please note that this opertor is an importable hack for two reasons:
// 1. No waranty is given thst a string ends with '\0'
// 2. If string::iterator is a pointer, the compiler will not compile
//    for ambiguity reasons. Which operator should it take? This or that
//    shipped with the STL?
ostream& operator<<(ostream& os, string::iterator iter)
{
	for(;*iter != '\0';++iter)
		os << *iter;
	return os;
}


int main()
{
	// p. 133 {{{
    string s1 = "abcdefghijk";
    string s2 = "def";

    string::iterator i = find_end(s1.begin(), s1.end(), s2.begin(), s2.end() );
    cout << i << endl;
	// }}}

    return 0;
}

/* Input: No input
*/
/* Output:
defghijk
*/