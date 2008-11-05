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
#include <algorithm>

using namespace ::std;

namespace book {

// p. 135 {{{
template <class charT = char, class Traits = char_traits<charT> >
class ostreambuf_iterator :
public iterator<output_iterator_tag, void, void, void, void>
{
    public:
        typedef charT                          char_type;
        typedef Traits                         traits_type;
        typedef basic_streambuf<charT, Traits> streambuf_type;
        typedef basic_ostream  <charT, Traits> ostream_type;


        ostreambuf_iterator(ostream_type& s) throw()
            : sbuf(s.rdbuf() ), failedFlag(false) {}

        ostreambuf_iterator(streambuf_type* sb) throw()
            : sbuf(sb), failedFlag(false) {}

        ostreambuf_iterator& operator= (const charT& t)
        {
            if ( failed() == false && sbuf != 0 )
            {        
                traits_type::int_type result;

                try
                {
                    result = sbuf->sputc(t);
                }

                catch(...)
                {
                    failedFlag = true;
                    throw;
                }

                if (traits_type::eq_int_type(result, traits_type::eof() ) )
                    failedFlag = true;
            } 
         
			// {{{
            // sbuf might be 0. In this case failedFlag should be set.
            failedFlag |= (sbuf == 0);
			// }}}                

            return *this;
        }

        ostreambuf_iterator& operator* ()    { return *this; }
        ostreambuf_iterator& operator++()    { return *this; }
        ostreambuf_iterator& operator++(int) { return *this; }
// }}}
// p. 136 {{{
        bool failed() const throw ()
        {
            return failedFlag;
        }

    private:
        bool failedFlag;
        streambuf_type * sbuf;
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
	char helloWorld[12] = "Hello world";
	copy(helloWorld, helloWorld+12, ns::ostreambuf_iterator<char>(cout));

	return 0;
}

/* Input: No input
*/
/* Output
Hello world
*/
