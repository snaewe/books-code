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

#include <locale>
#include <iostream>

using namespace ::std;

// p. 330 {{{
template <class charT>
class umlaut : public ctype_byname<charT>
{
    protected:
        virtual bool do_is_umlaut(charT c) const
        {
            switch(narrow(c,'?'))
            {
                case 'ä': case 'ö': case 'ü':
                case 'Ä': case 'Ö': case 'Ü': return true;
                default:                      return false;
            }
        }
    public:
        explicit umlaut(size_t refs = 0) : ctype_byname<charT>("German", refs) { }

        bool is_umlaut(charT c) const {
            return do_is_umlaut(c);
        }
};
// }}}

int main()
{
	// p. 330 {{{
	locale loc(locale("German"), new umlaut<char>);

	if ( has_facet<umlaut<char> >(loc) )
	{    
		const umlaut<char>& ufac = use_facet<umlaut<char> >(loc);
		cout << ufac.is(ctype_base::alpha,'Ä') << endl;
		cout << ufac.is_umlaut('Ä') << endl;
	// }}}
		// p. 331 {{{
		const ctype<char>& cfac = use_facet<ctype<char> >(loc);
		cout << cfac.is(ctype_base::alpha, 'Ä') << endl;
		/*
		cout << cfac.is_umlaut('Ä')<< endl; // error: is_umlaut() is not accessible 
		// through a ctype reference
		*/
		// }}}
	}    


	// p. 331 {{{
	umlaut<char> fac(1);
	cout << fac.is(ctype_base::alpha,'Ä') << endl;
	cout << fac.is_umlaut('Ä') << endl;
	// }}}

    return 0;
}

/* Input: No input
*/
/* Output: Please note that the output for true is 1.
1
1
1
1
1
*/