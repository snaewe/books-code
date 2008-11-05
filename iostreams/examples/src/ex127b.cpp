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
#include <algorithm>
#include <iterator>

using namespace ::std;

// we are using namespace book to avoid clashes with implementations in namespace ::std
namespace book {

// p. 127 {{{
template<class T, class charT = char, class traits = char_traits<charT> >
class ostream_iterator : 
    public iterator<output_iterator_tag, void, void, void, void>
{
public:
    typedef charT char_type;
    typedef traits traits_type;
    typedef basic_ostream<charT, traits> ostream_type;

    ostream_iterator(ostream_type&s, const charT* d = 0)
        : ost(&s), delim(d) {}

    ostream_iterator& operator= (const T& t)
    {
        *ost << t;
        if (delim != 0)
            *ost << delim;
        return *this;
    }

    ostream_iterator& operator *()     { return *this; }
    ostream_iterator& operator ++()    { return *this; }
	// }}}
	// p. 128 {{{
    ostream_iterator& operator ++(int) { return *this; }
private:
    const charT* delim;
    basic_ostream<charT, traits>* ost;
};

// }}}

}; // namespace ::book

//*
namespace ns = book;
/*/
namespace ns = std;
//*/

int main()
{
	ns::ostream_iterator<int> out(cout,"/");
	for (int i = 0; i<10; ++i) out = i;
	cout << endl;

	int primes[10] = {2,3,5,7,11,13,17,19,23,29};
	copy(primes, primes+10, ns::ostream_iterator<int>(cout, " * ")); // STL - copy

	return 0;
}

/* Input: No input
*/
/* Output
0/1/2/3/4/5/6/7/8/9/
2 * 3 * 5 * 7 * 11 * 13 * 17 * 19 * 23 * 29 *
*/

