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

// According p. 183 - 184 upper part mendl -> basic_mendl renamed


#include <iostream>

using namespace ::std;


#include "basic_mendl_183.h"
#include "mendl_184.h"

int main()
{
	cout << "*****"; // 

	/*
	// Does not compile, template arguement is missing
	// p. 183 {{{
	cout << mendl(5);
	wcout << mendl(5);
	// }}}
	//*/

	// p. 183 {{{
	cout << basic_mendl<char>(5) <<  "basic_mendl<char>(5)";
	wcout << basic_mendl<wchar_t>(5) << L"basic_mendl<wchar_t>(5)";
	// }}}

	typedef basic_mendl<char> cmendl;
	typedef basic_mendl<wchar_t> wmendl;

	cout << cmendl(5);
	// {{{
	cout << "cmendl(5)";
	// }}}
	wcout << wmendl(5);
	// {{{
	wcout << L"wmendl(5)";
	// }}}
// }}}
// p. 184 {{{
	cout << mendl(5, cout);
	// {{{
	cout << "mendl(5, cout)";
	// }}}
	wcout << mendl(5, wcout);
	// {{{
	wcout << L"mendl(5, wcout)";
	// }}}
// }}}
	cout << "*****"; // 

	return 0;
}

/* Input: No input
*/
/* Output:
*****




basic_mendl<char>(5)




basic_mendl<wchar_t>(5)




cmendl(5)




wmendl(5)




mendl(5, cout)




mendl(5, wcout)*****
*/