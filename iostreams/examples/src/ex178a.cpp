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

using namespace ::std;

namespace book {
	
// p. 178 {{{
template <class charT, class traits>
inline basic_ostream<charT, traits>& endl(basic_ostream<charT, traits>& os)
{
	os.put( os.widen('\n') );
	os.flush();

	return os;
}
// }}}

} // namespace book

int main()
{
	cout << "Before book::endl";
	// p. 178 {{{
	cout << book::endl; // !!! We must write book::endl to avoid confusion with std::endl;
	// }}}
	cout << "After book::endl";
	cout << std::endl; // Step through this code to see what your implementation does.

    return 0;
}


/* Input: No input
*/
/* Output:
Before book::endl
After book::endl
*/