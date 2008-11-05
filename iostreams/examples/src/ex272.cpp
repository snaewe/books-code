/*
authors:    "Angelika Langer" <langer@camelot.de>
			"Klaus Wittlich" <Klaus_Wittlich@sae.de> 

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
#include <iterator>
#include <string>
#include <memory>
#include <iostream>

using namespace ::std;
// {{{
// According to footnote we need a string_inserter for it is not provided by the standard
template <class charT,  class Traits=char_traits<charT>, class Allocator=allocator<charT> >
class string_inserter
	: public iterator<output_iterator_tag, void, void, void, void>
{
protected:
	basic_string<charT,Traits,Allocator>* container;
	typename basic_string<charT,Traits,Allocator>::iterator iter;

public:
	typedef basic_string<charT,Traits,Allocator> container_type;
	string_inserter(basic_string<charT,Traits,Allocator>& x, typename basic_string<charT,Traits,Allocator>::iterator i);
	string_inserter& operator=(typename basic_string<charT,Traits,Allocator>::const_reference value);

	string_inserter& operator*();
	string_inserter& operator++();
	string_inserter& operator++(int);
};

template <typename charT,  typename Traits, typename Allocator >
inline
string_inserter<charT,Traits,Allocator>::string_inserter(basic_string<charT,Traits,Allocator>& x, typename basic_string<charT,Traits,Allocator>::iterator i)
	: container(&x),
	  iter(i)
{
}

template <typename charT,  typename Traits, typename Allocator >
inline
string_inserter<charT,Traits,Allocator>&
string_inserter<charT,Traits,Allocator>::operator=(typename basic_string<charT,Traits,Allocator>::const_reference value)
{
	iter = container->insert(iter, value);
	++iter;
	return *this;
}

template <typename charT,  typename Traits, typename Allocator >
inline
string_inserter<charT,Traits,Allocator>&
string_inserter<charT,Traits,Allocator>::operator*()
{
	return *this;
}

template <typename charT,  typename Traits, typename Allocator >
inline
string_inserter<charT,Traits,Allocator>&
string_inserter<charT,Traits,Allocator>::operator++()
{
	return *this;
}

template <typename charT,  typename Traits, typename Allocator >
inline
string_inserter<charT,Traits,Allocator>&
string_inserter<charT,Traits,Allocator>::operator++(int)
{
	return *this;
}

template <typename charT,  typename Traits, typename Allocator, class Iterator>
inline
string_inserter<charT,Traits,Allocator>
make_string_inserter(basic_string<charT,Traits,Allocator>& x, Iterator i)
{
	return string_inserter<charT,Traits,Allocator>(x, i);
}
// }}}


int main()
{
	// p. 272 {{{
	locale loc;

	if (has_facet<money_put<char> >(loc) ) // always yields true
	// {{{
	{
	// }}}
		const money_put<char>& fac1
			= use_facet<money_put<char> >(loc);
	// {{{
		cout << "fac1 can be used" << endl;
	}
	// }}}

	if (has_facet<money_put<char, string_inserter<char> > >(loc))
	// {{{
	{
	// }}}
		const money_put<char, string_inserter<char> >& fac2
			= use_facet<money_put<char, string_inserter<char> > >(loc);
	// {{{
		cout << "fac2 can be used" << endl;

		string s("***");
		string_inserter<char> ins = make_string_inserter(s, s.end() );

		ins = fac2.put(ins,false,cout,'#',123456);
		cout << s << endl;
	}
	// }}}
	// }}}

    return 0;
}

/* Input: No Input
*/
/* Output:
fac1 can be used
fac2 can be used
***123456
*/
