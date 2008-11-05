/*
author:  "Klaus Wittlich" <Klaus_Wittlich@sae.de> 

Based on source code published in the book "Standard C++ IOStreams 
and Locales" by Angelika Langer & Klaus Kreft, Copyright (c) 2000 by 
Addison Wesley Longman, Inc.

Permission to use, copy, and modify this software for any non-profit
purpose is hereby granted without fee.  Neither the author of this 
source code, Klaus Wittlich, nor the authors of the above mentioned 
book, Angelika Langer and Klaus Kreft, nor the publisher, Addison
Wesley Longman, Inc., make any representations about the suitability of this 
software for any purpose.  It is provided "as is" without express or 
implied warranty.
*/

#include <locale>
#include <iostream>

using namespace ::std;

int main()
{
	locale loc;
	char c = 'x';
	cout << "The upper of " << c << " is " <<
	// p. 278 {{{
		use_facet<ctype<char> >(loc).toupper(c);
	// }}}
	cout << endl;

	char lac[5] = "abcd";
	char * cp1 = lac;
	char * cp2 = cp1 + 4;
	cout << "The upper of " << lac << " is ";
	// p. 278 {{{
	use_facet<ctype<char> >(loc).toupper(cp1,cp2);
	// }}}
	cout << cp1 << endl;
	
	return 0;
}

/* Input: No input
*/
/* Output:
The upper of x is X
The upper of abcd is ABCD
*/