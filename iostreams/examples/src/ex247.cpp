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

#include <sstream>
#include <iostream>

using namespace ::std;

// p. 247 {{{
template <class charT,
          class Traits = char_traits<charT>,
          class Allocator = allocator<charT> >
          class my_stringbuf : public basic_stringbuf<charT, Traits, Allocator>
{
    public:
        int_type scontainc (char_type c)
        {
            int_type cnt = 0;

            if (gptr() == egptr() )
                underflow();

            for ( int_type i = 0; gptr() != 0 && gptr()+i != egptr(); ++i )
            {     
                if (*(gptr()+i) == c)
                    ++cnt;
            }     
            return cnt;
        }

        my_stringbuf() { }
		// {{{
		explicit my_stringbuf(const basic_string<charT, Traits, Allocator>& str,
			ios_base::openmode which = ios_base::in | ios_base::out)
			: basic_stringbuf<charT, Traits, Allocator>(str, which) {}
		// }}} 
    private:
        // prohibit copying and assignment
        my_stringbuf(const my_stringbuf&);
        my_stringbuf& operator =(const my_stringbuf&);
};
// }}}

int main()
{
	my_stringbuf<char> strbuf("The rain in Spain Stays mainly in the plain.");
	istream str(&strbuf);

	string s;

	cout << "Initial " << strbuf.scontainc('a') << " 'a's" << " unread" << endl;

	while(!str.eof())
	{
		str >> s;
		cout << "After reading '" << s << "' " << strbuf.scontainc('a') << " 'a's" << " unread" << endl;
	}

    return 0;
}

/* Input: No Input
*/
/* Output:
Initial 5 'a's unread
After reading 'The' 5 'a's unread
After reading 'rain' 4 'a's unread
After reading 'in' 4 'a's unread
After reading 'Spain' 3 'a's unread
After reading 'Stays' 2 'a's unread
After reading 'mainly' 1 'a's unread
After reading 'in' 1 'a's unread
After reading 'the' 1 'a's unread
After reading 'plain.' 0 'a's unread
*/