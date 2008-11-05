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


namespace book {
// p. 278 {{{
template <class charT> bool isupper (charT c, const locale& loc)
{
    return use_facet<ctype<charT> >(loc).is(ctype_base::upper, c);
}
// }}}
}


int main()
{
	locale loc;
	char c = 'X';
	bool b = 
	// p. 278 {{{
	use_facet<ctype<char> >(loc).is(ctype_base::lower, c);
	// }}}
	cout << c << " is lower? " << (b ? "true" : "false") << endl;

	ctype<char>::mask m = 0;
	b = 
	// p. 278 {{{
	use_facet<ctype<char> >(loc).is(&c, &c+1, &m);
	// }}}
	cout << "mask of " << c << " is " << m << endl;

	b = book::isupper(c,loc);
	cout << c << " is " << (b ? "" : " not ") << "upper" << endl;

    return 0;
}

/* Input: No input
*/
/* Output:
X is lower? false
mask of X is 1
X is upper
*/