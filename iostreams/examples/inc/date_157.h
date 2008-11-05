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
#include "date_157.h"
*/

#ifndef DATE_H
#define DATE_H

// p. 148 {{{
class date {
public:
    date(int d, int m, int y)
    {
        tm_date.tm_mday = d;tm_date.tm_mon = m-1; tm_date.tm_year = y-1900;
        tm_date.tm_sec = tm_date.tm_min = tm_date.tm_hour = 0;
        tm_date.tm_wday = tm_date.tm_yday = 0;
        tm_date.tm_isdst = 0;
		mktime(&tm_date); 
    }
    date(const tm& t) : tm_date(t) {}
    date()
    {
        time_t ltime;
// }}}
// p. 149 {{{
        time(&ltime);
        tm_date = *localtime(&ltime);
    }
    // more constructors and useful member functions

private:
    tm tm_date;

    template<class charT, class Traits>
    friend basic_istream<charT, Traits>& 
    operator >>(basic_istream<charT, Traits>& is, date& dat);

    template<class charT, class Traits>
    friend basic_ostream<charT, Traits>&
    operator<< (basic_ostream<charT, Traits>& os, const date& dat);
};
// }}}

// p. 157 {{{
template <class charT, class Traits>
basic_istream<charT, Traits>&
operator>>(basic_istream<charT, Traits>& is, date& dat)
{
    if (!is.good() )
        return is;

    ios_base::iostate err = ios_base::goodbit;

    use_facet<time_get<charT, istreambuf_iterator<charT, Traits> > >(is.getloc() )
        .get_date(is, istreambuf_iterator<charT, Traits> (), is, err, &dat.tm_date);

    return is;
}

template <class charT, class Traits>
basic_ostream<charT, Traits>&
operator<< (basic_ostream<charT, Traits>& os, const date& dat)
{
    if (!os.good() )
        return os;

    use_facet<time_put<charT, ostreambuf_iterator<charT, Traits> > >(os.getloc() ) 
        .put(os, os, os.fill(), &dat.tm_date,'x');

	return os;
}
// }}}

#endif