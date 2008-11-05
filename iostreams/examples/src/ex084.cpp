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

// For reasons of demonstrating we need our own basic_istream encapsulated in namespace book.
// This class is the same as shipped with the compiler, but with an operator>> as described in the book.
template <class charT, class Traits = char_traits<charT> >
struct basic_ostream : public std::basic_ostream<charT, Traits>
{
	// p. 84 {{{
	basic_ostream<charT, Traits>& operator <<(int n)
	{
		if (
			use_facet<num_put<charT, ostreambuf_iterator<charT, Traits> > >
			(this->getloc()).put(*this, *this, basic_ios<charT, Traits>::fill(), static_cast<long>(n) ) // !!! static_cast<long> is different from book.
																									    // Otherwise the example does not compile.
			.failed()
		)
		this->setstate(ios_base::badbit); // set the stream's state accordingly

		return *this;
	}
	// }}}
};

} // namespace book

int main()
{
	book::basic_ostream<char>& b_ostr = static_cast< book::basic_ostream<char>& > ( cout  );

	b_ostr << 50;

    return 0;
}

/* Input: No input
*/
/* Output:
50
*/