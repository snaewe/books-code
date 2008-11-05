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
#include <sstream>
#include <iostream>

using namespace ::std;


int main()
{
	// p. 296 {{{
	ostringstream oss; 
	locale loc("American_USA.1252"); 
	oss.imbue(loc); 
	const time_put<char>& tfac = use_facet<time_put<char> >(loc); 
	struct tm xmas = { 0, 0, 12, 25, 11, 93 }; 
	string fmt("This is %A, day %d of month %B in the year %Y.\n"); 
	time_put<char>::iter_type ret  
	= tfac.put(oss,oss,' ',&xmas, 
			fmt.c_str(),fmt.c_str()+fmt.length()); 
	cout << oss.str() << endl; 
	// }}}

    return 0;
}

/* Input: No input
*/
/* Output:
This is Sunday, day 25 of month December in the year 1993.
*/