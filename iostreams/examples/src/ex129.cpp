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

#include <iterator>
#include <iostream>
#include <fstream>

using namespace ::std;

namespace book {

// p. 129 {{{
template <class T, class charT = char,
    class Traits = char_traits<charT>, class Distance = ptrdiff_t>
class istream_iterator :
public iterator<input_iterator_tag, T, Distance, const T*, const T&>
{
    friend bool operator==
        (const istream_iterator<T, charT, Traits,Distance>& lhs,
         const istream_iterator<T, charT, Traits,Distance>& rhs)
    {
        return (lhs.istp == rhs.istp);
    }

    friend bool operator != 
        (const istream_iterator<T, charT, Traits,Distance>& lhs,
         const istream_iterator<T, charT, Traits,Distance>& rhs)
    {
        return (! (lhs == rhs) );
    }

    public:
        typedef charT char_type;
        typedef Traits traits_type;
        typedef basic_istream<charT, Traits> istream_type;

        istream_iterator() : istp(0) {}
        istream_iterator(istream_type& s) : istp(&s) { readElem(); }

        const T& operator* () const {return value;}
        const T* operator->() const {return &value;}

        istream_iterator& operator++()
        {
            readElem();
            return *this;
        }
// }}}
// p. 130 {{{
        istream_iterator operator++(int)
            {
            istream_iterator tmp = *this;
            readElem();
            return tmp;
        }

    private:
        void readElem()
        {
            if (istp != 0)
                if (!(*istp >> value) )
                    istp = 0;
        }

        basic_istream<charT, Traits> * istp;
        T value;
};

// }}}

} // namespace book 

//*
namespace ns = book;
/*/
namespace ns = std;
//*/

int main()
{
	fstream instr("ex129.in");
	for (ns::istream_iterator<int> input(instr); input != ns::istream_iterator<int>(); ++input)
	{
		int i = *input;
		cout << i << " ";
	}

	return 0;
}

/* Input: File ex129.in
*/
/* Output:
1 1 2 6 24 120 720 5040 40320 362880 3628800
*/

