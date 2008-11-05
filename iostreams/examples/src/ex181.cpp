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


#include <iostream>
#include <iomanip>

using namespace ::std;

#include "one_arg_manip_181.h"
#include "width_181.h"

/* // Activate this block to see the compiler error
// p. 182 {{{
class mendl : public one_arg_manip<unsigned int>
{
public:
    explicit mendl(unsigned int i) : one_arg_manip<unsigned int>(mendl::fct, i) {}
private:
    static void fct (ios_base& os, unsigned int n)
    {
        for ( int i = 0; i<n; ++i )
            os.put(os.widen('\n'));     // error: os is not an output stream,
        os.flush();                     // but a reference to a ios_base object
    }
};
// }}}
//*/

int main()
{
    int j;
    cout << "Enter an integer" << endl;
    cin >> j;
    cout << "you entered " << width(10) << j << endl;
// p. 190 {{{
	for ( unsigned int i = 0; i<9; ++i )
		cout << width(i) << 'x' << endl;
// }}}

    return 0;
}


/* Input:
23
*/
/* Output:
Enter an integer
you entered         23
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
/* Screen shot:
Enter an integer
23
you entered         23
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