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

#include <ctime>
#include <iostream>
#include <iomanip>
#include <locale>

using namespace ::std;

#include "date_157.h"

int main()
{
	// p. 149 {{{
    date eclipse(11,8,1999);
    cout << "solar eclipse on " << eclipse << '\n';

    date aDate;
    cout << '\n' << "Please enter a date (day month year):" << '\n';
    cin >> aDate;
    cout << "date: " << aDate << endl;
	// }}}

    return 0;
}

/* Input:
2 6 1952
*/
/* Output:
solar eclipse on 08/11/99

Please enter a date (day month year):
date: 06/02/52
/* Screen contents:
solar eclipse on 08/11/99

Please enter a date (day month year):
2 6 1952
date: 06/02/52
*/