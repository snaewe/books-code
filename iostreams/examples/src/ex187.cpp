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

#include <iostream>
#include <iomanip>

using namespace ::std;

#include "one_arg_manip_weh_187.h"
#include "bounded_width_190.h"

// Needed for example for one_arg_manip_weh
void SetBoolAlpha(ios_base& aBase, bool aSet)
{
	if (aSet)
		aBase.flags(aBase.flags() | ios_base::boolalpha);
	else
		aBase.flags(aBase.flags() & ~ios_base::boolalpha);
}

int main()
{
	cout << one_arg_manip_weh<bool>(SetBoolAlpha, true) << true << endl;
	cout << one_arg_manip_weh<bool>(SetBoolAlpha, false) << true << endl;
	
	cout << endl << endl;


	// p. 189 {{{
	bounded_width width_2_6(2,6);
	for ( unsigned int i = 0; i<9; ++i )
		cout << width_2_6(i) << 'x' << endl;
	// }}}

    return 0;
}

/* Input: No input
*/
/* Output:
true
1


 x
 x
 x
  x
   x
   x
   x
   x
   x
*/