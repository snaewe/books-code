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
	locale holland_help("Dutch");
	// p. 269 {{{
	moneypunct<char>& mfac = // ... provide Dutch monetary facet somehow ...; 
	// {{{
		const_cast<moneypunct<char>&>(use_facet<moneypunct<char> >(holland_help)); 
	// }}}
	locale dutch_german (locale("German"),&mfac);

	locale holland("Dutch");
	dutch_german = locale("German").combine<moneypunct<char> >(holland);
	// }}}

	// p. 270 {{{
	locale polish_german_1(locale("German"),"Polish",locale::monetary);
	cout << "german_base polish monetary: " << polish_german_1.name() << endl;
	locale polish_german_2(locale("German"), locale("Polish"), locale::time);
	cout << "german_base polish_time    : " << polish_german_2.name() << endl;
	// }}}

    return 0;
}

/* Input: No input
*/
/* Output:
german_base polish monetary: Polish_Poland.1250
german_base polish_time    : Polish_Poland.1250
*/
