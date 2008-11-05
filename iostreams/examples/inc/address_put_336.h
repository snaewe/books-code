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
#include "address_put_336.h"
*/

#ifndef ADDRESS_INSERTER_H
#define ADDRESS_INSERTER_H

// p. 335 {{{
template <class charT, class OutIter = ostreambuf_iterator<charT> >
class address_put : public locale::facet
{
	protected:
		typedef basic_string<charT> String;

    public:
        typedef OutIter iter_type;

        static locale::id id;

        address_put(size_t refs = 0) : locale::facet(refs) { }

        void put(OutIter oi,
            const String& firstname, const String& secname, const String& lastname,
            const String& address1,  const String& address2,
            const String& town,      const String& zipcode, const String& state,
            const String& country,   const String& cntrycode) const
        {
            do_put(oi, firstname, secname, lastname, 
                address1, address2, town, zipcode, state, country, cntrycode); 
        }
// }}}
// p. 337 {{{
    protected:
        virtual void do_put(OutIter oi,
            const String& firstname, const String& secname, const String& lastname,
            const String& address1,  const String& address2,
            const String& town,      const String& zipcode, const String& state,
            const String& country,   const String& cntrycode) const = 0; // was not = 0 on page 335
// }}}
// p. 335 {{{
        void put_string(OutIter oi, String s) const
        {
            typename String::iterator si, end;

            for (si = s.begin(), end = s.end(); si != end; si++, oi++)
                *oi = *si;
        }
};
// }}}

#endif