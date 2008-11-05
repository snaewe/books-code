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

/*
#include "address_333.h"
*/

#ifndef ADDRESS_H
#define ADDRESS_H

// p. 333 {{{
template <class charT>
class address
{
	friend basic_ostream<charT>&
		operator << (basic_ostream<charT>& os, const address<charT>& ad)
		// p. 338 {{{
		// It is necessary to inline this operator, otherwise a link error occurs.
		{
			locale loc = os.getloc();

			try
			{
				const address_put<charT>& apFacet = use_facet<address_put<charT> >(loc);
				apFacet.put(os, ad.firstname_, ad.secname_, ad.lastname_, 
					ad.address1_, ad.address2_, ad.town_, ad.zipcode_,
					ad.state_, ad.country_, ad.cntrycode_);
			}
			catch(bad_cast&)
			{
				// locale does not contain a address_put facet;
			}

			return (os);
		}
		// }}}

	typedef basic_string<charT> String;

public:
	address(const String& firstname, const String& secname,
		    const String& lastname,
			const String& address1,  const String& address2,
			const String& town,		 const String& zipcode,
			const String& state,     const String& country,
			const String& cntrycode)
			: firstname_(firstname) , secname_(secname), lastname_(lastname),
			  address1_(address1), address2_(address2),
			  town_(town),	zipcode_(zipcode), state_(state),     
			  country_(country), cntrycode_(cntrycode) {}
private:
	String firstname_;
	String secname_;
	String lastname_;
	String address1_;
	String address2_;
	String town_;
	String zipcode_;
	String state_;
	String country_;
	String cntrycode_;
};
// }}}

#endif