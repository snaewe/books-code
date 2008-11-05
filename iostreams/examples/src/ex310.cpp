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
#include <iterator>
#include <iostream>

using namespace ::std;

#include "standalonefacet_309.h"

int main()
{
	// p. 310 {{{
	StandAloneFacet<num_put<char, back_insert_iterator<string> > > fac;
	basic_ios<char> str(0);
	str.imbue(locale("German"));
	// {{{
	string hw("Hello World - ");
	// }}}
	fac.put(back_inserter(hw), str, ' ', (unsigned long)12345678L); // !!! hw instead "Hello World - "
	// }}}

	cout << hw << endl;

	return 0;
}

/* Input:
*/
/* Output:
Hello World - 12.345.678
*/