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

template <class charT, class Traits = char_traits<charT> >
struct basic_ostream : public std::basic_ostream<charT, Traits>
{
	// p. 80 {{{
	book::basic_ostream<charT, Traits>& operator <<(int n) // !!! slight different from book for the operator is implemented inline
	{
		use_facet<num_put<charT, ostreambuf_iterator<charT, Traits> > >
			(this->getloc()).put(*this, *this, basic_ios<charT, Traits>::fill(), static_cast<long>(n) ); // !!! static_cast<long> is different from book.
																									     // Otherwise the example does not compile.
		return *this;
	}
	// }}}
};

template <class charT, class traits = char_traits<charT> >
struct basic_istream : public std::basic_istream<charT, traits>
{
	// p. 80 {{{
	basic_istream<charT, traits>& operator >>(int& n) // !!! slight different from book for the operator is implemented inline
	{
		ios_base::iostate err = 0;
		long l; // !!! Helper, for line (this->getloc().... does not compile with int parameter.

		use_facet<num_get<charT, istreambuf_iterator<charT, traits> > >
			(this->getloc()).get(*this, istreambuf_iterator<charT, traits>(), *this, err, l ); // !!! l instead n used
		n = l; // !!! 
		return *this;
	}
	// }}}
};

} // namespace book

int main()
{
	book::basic_istream<char>& b_istr = static_cast<book::basic_istream<char>&> ( cin  );
	book::basic_ostream<char>& b_ostr = static_cast<book::basic_ostream<char>&> ( cout );
	
	int i;
	b_istr >> i;
	b_ostr << 2 * i;

    return 0;
}

/* Input:
10
*/
/* Output:
20
*/
