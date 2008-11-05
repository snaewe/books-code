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
#include <map>
#include <iostream>

using namespace ::std;

#include "address_333.h"
#include "address_put_336.h"
#include "us_address_put_337.h"
#include "german_address_put_337.h"
#include "locale_factory_340.h"

locale::id address_put<char>::id;

// {{{ p. 342
//void printAddress(ostream& os, const address& addr, locale loc) // !!! addr
void printAddress(basic_ostream<char>& os, address<char> addr, locale loc) // !!! addr
{
	locale original = os.imbue(loc);
	os << addr << endl; // !!! addr
	os.imbue(original);
}
// }}}

address_locale_factory adrFact;

int main()
{
	address<char> myAddress("firstname", "secname", "lastname", "address1", "address2", "town",
		"zipcode","state", "country", "cntrycode");

	cout << "German address: " << endl;
// {{{ p. 342
	printAddress(cout,myAddress, address_locale_factory().make_locale("German"));
// }}}
	cout << "-----------------------------------------------------" << endl;
	cout << "US address: " << endl;
	printAddress(cout,myAddress, address_locale_factory().make_locale("US"));

    return 0;
}

/* Input: No input
*/
/* Output:
German address:
firstname lastname
address1
address2

cntrycode-zipcode town

-----------------------------------------------------
US address:
firstname secname lastname
address1
address2
town, state zipcode
country
*/