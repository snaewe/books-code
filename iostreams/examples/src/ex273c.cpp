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
	// p. 273 {{{
	locale german("German");
	const numpunct<char>& fac = use_facet<numpunct<char> >(german);
	cout << "true in German: " << fac.truename() << endl;
	// }}}

    return 0;
}

/* Input: No input
*/
/* Output:
true in German: true
*/
/* Annotation: This seems to be a MS - Bug. "true" in German is "wahr", "true" is not a German word.
*/