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
#include <cassert>

using namespace ::std;

namespace book {

// p. 137 {{{
template <class charT, class traits = char_traits<charT> >
    class istreambuf_iterator
    : public iterator<input_iterator_tag, charT,
                               typename traits::off_type, charT*, charT&>
{

    public:
        typedef charT                          char_type;
        typedef traits                         traits_type;
        typedef typename traits::int_type      int_type;
        typedef basic_streambuf<charT, traits> streambuf_type;
        typedef basic_istream< charT, traits>  istream_type;

        class proxy // !!! not as template class
        {
            friend class istreambuf_iterator<charT, traits>;

        public:
            charT operator*() { return keep_; }

        private:
            proxy(charT c, streambuf_type * sb) : keep_(c), sbuf(sb) {}

            charT keep_;
            basic_streambuf<charT, traits>* sbuf;
        };
// }}}
// p. 138 {{{
        istreambuf_iterator()                    throw() : sbuf(0)         {}
        istreambuf_iterator( istream_type& s)    throw() : sbuf(s.rdbuf()) {}
        istreambuf_iterator( streambuf_type* sb) throw() : sbuf(sb)        {}
        istreambuf_iterator( const proxy& p)     throw() : sbuf(p.sbuf)    {}

        charT operator* () const
        {
            if (sbuf)
                return (sbuf->sgetc() );
            else
                return 0;
        }

        istreambuf_iterator& operator++()
        {
            if ( sbuf )
            {        
                sbuf->sbumpc();
                if (traits::eq_int_type(sbuf->sgetc(), traits::eof() ) )
                    sbuf = 0;
            }        
            return *this;
        }

        proxy operator++(int)
        {
            if ( sbuf )
            {        
                proxy temp(sbuf->sgetc(), sbuf);
                sbuf->sbumpc();
                if (traits::eq_int_type(sbuf->sgetc(), traits::eof() ) )
                    sbuf = 0;
                return temp;
            }        
            else
                return proxy(0, 0);
        }

        bool equal(const istreambuf_iterator& b) const
        {
            if ( ( ( sbuf == 0) && (b.sbuf == 0) ) || ((sbuf != 0) ) )
                return true;
            else
                return false;
        }
// }}}
// p. 139 {{{
    private:
        streambuf_type* sbuf;

};

template <class charT, class traits>
bool operator == (const istreambuf_iterator<charT, traits>& lhs,
                  const istreambuf_iterator<charT, traits>& rhs)
{
    return lhs.equal(rhs);
}

template <class charT, class traits>
bool operator != (const istreambuf_iterator<charT, traits>& lhs,
                  const istreambuf_iterator<charT, traits>& rhs)
{
    return (!(lhs == rhs) );
}
// }}}

} // namespace ::book

//*
namespace ns = book;
/*/
namespace ns = std;
//*/

int main()
{
	char array[11];
	array[10] = '\0';

	ns::istreambuf_iterator<char> it(cin);
	for (int i=0; i<10; ++i, ++it)
		array[i] = *it;
	cout << "you typed \"" << array << "\"" << endl;

	for (int i=0; i<10; ++i, it++)
		array[i] = *it;
	cout << "you typed \"" << array << "\"" << endl;

	// A short test for == ans != 
	assert(it == it);
	assert (! (it != it));

	return 0;
}

/* Input: (Press enter after each line)
abcdefghijklmnopqrstuvwxyz
*/
/* Output
you typed "abcdefghij"
you typed "klmnopqrst"
*/
