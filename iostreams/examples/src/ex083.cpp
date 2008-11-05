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
template <class charT, class traits = char_traits<charT> >
struct basic_istream : public std::basic_istream<charT, traits>
{
	// p. 83 {{{
	basic_istream<charT, traits>&
	operator >>(int& n)
	{
		ios_base::iostate err = 0;

		long l; // !!! Helper, for get(....) does not compile with int parameter.
		use_facet<num_get<charT, istreambuf_iterator<charT, traits> > >(this->getloc())
		.get(*this,
			istreambuf_iterator<charT, traits>(),
			*this,
			err,                    //provide an iostate object to the facet
			l); // !!! l used instead of n
		n = l; // !!! 
		if (err) 
			this->setstate(err); // set the streams state accordingly
		return *this;
	}
	// }}}
};

} // namespace book


int main()
{
	book::basic_istream<char>& b_istr = static_cast<book::basic_istream<char>&> ( cin  );
	
	int i1, i2;
	b_istr >> i1;
	cerr << "error state (1): " << b_istr.rdstate() << endl;
	b_istr >> i2;
	cerr << "error state (2): " << b_istr.rdstate() << endl;

    return 0;
}

/* Input:
10 abc
*/
/* Output:
error state (1): 0
error state (2): 2
*/
