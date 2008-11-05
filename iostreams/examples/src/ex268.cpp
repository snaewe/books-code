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
	// p. 268 {{{
	locale native("");
	locale usa("American_USA.1252");
	locale holland("Dutch");
	locale global;

	cout << "native : " << native.name() << endl;
	cout << "classic: " << locale::classic().name() << endl;
	cout << "global : " << global.name() << endl;
	cout << "holland: " << holland.name() << endl;
	cout << "usa    : " << usa.name() << endl;
	// }}}

	return 0;
}

/* Input: No input. Please regard: other countries, other outputs. Your output for native might differ elsewhere. 
*/
/* Output:
native : German_Germany.1252
classic: C
global : C
holland: Dutch_Netherlands.1252
usa    : English_United States.1252
*/