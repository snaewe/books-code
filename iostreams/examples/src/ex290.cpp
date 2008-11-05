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
#include <limits>

using namespace ::std;

// p. 290 {{{
template <class String>
ios_base::iostate int_get(const String& s, ios_base& ib, int& i)
{
    typedef String::value_type charT;
    typedef String::const_iterator iterT;
    long l;
    ios_base::iostate err = 0; //!!! Initialzation was not in book but is necessary.
    iterT in  = s.begin();
    iterT end = s.end();

    use_facet<num_get<charT, iterT> > (ib.getloc()).get(in, end, ib, err, l);

    if ( !(err & ios_base::failbit) && !(err & ios_base::badbit) )
    {        
        if (numeric_limits<int>::min() <= l && l <= numeric_limits<int>::max() )
            i = l;
        else
            err |= ios_base::failbit;
    }        

    return err;
}
// }}}

int main()
{
	string s("1234");
	int i = 0;
	int_get(s,cout,i);

	cout << "string " << s << " was parsed to int " << i << endl;

    return 0;
}

/* Input: No input
*/
/* Output:
string 1234 was parsed to int 1234
*/