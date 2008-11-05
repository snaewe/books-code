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
	// p. 321 {{{
	locale loc(locale("German"), new ctype_byname<char>("US", 0));
	// }}}

	char cOld, cNew;

	cOld = 'x';
	cNew = use_facet<ctype_byname<char> >(loc).toupper(cOld);
	if (cOld != cNew)
		cout << cOld << " changed to " << cNew << endl;
	else
		cout << cOld << " remained unchanged " << endl;


	cOld = 'ä';
	cNew = use_facet<ctype_byname<char> >(loc).toupper(cOld);
	if (cOld != cNew)
		cout << cOld << " changed to " << cNew << endl;
	else
		cout << cOld << " remained unchanged " << endl;

    return 0;
}

/* Input: No input
*/
/* Output: Please note that ä in OEM is displayed as ö DOS - ASCII
x changed to X
õ changed to -
*/