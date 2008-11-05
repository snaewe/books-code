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
#include "us_address_put_337.h"
*/

#ifndef US_ADDRESS_PUT_H
#define US_ADDRESS_PUT_H

// p. 337 {{{
template <class charT, class OutIter = ostreambuf_iterator<charT> >
class US_address_put : public address_put<charT, OutIter>
{
    public:
        US_address_put(size_t refs = 0) : address_put<charT, OutIter>(refs) {}

    protected:
        void do_put (OutIter oi,
            const String& firstname, const String& secname, 
            const String& lastname,
            const String& address1,  const String& address2,
            const String& town,      const String& zipcode, 
            const String& state,
            const String& country,   const String& cntrycode) const
        {
            String s(firstname);
            s.append(" ").append(secname).append(" ").append(lastname)
                .append("\n");
            s.append(address1).append("\n");
            if (!address2.empty())
                s.append(address2).append("\n");
            s.append(town).append(", ").append(state).append(" ").append(zipcode)
                .append("\n");
            if (!country.empty())
                s.append(country).append("\n");

            put_string(oi, s);
        }
};
// }}}

#endif