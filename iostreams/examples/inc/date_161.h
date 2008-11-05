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
#include "date_161.h"
*/

#ifndef DATE_H
#define DATE_H

// p. 161 {{{
class date {
public:
    date(int d, int m, int y)
    {
        tm_date.tm_mday = d; tm_date.tm_mon = m-1; tm_date.tm_year = y-1900;
        tm_date.tm_sec = tm_date.tm_min = tm_date.tm_hour = 0;
        tm_date.tm_wday = tm_date.tm_yday = 0;
        tm_date.tm_isdst = 0;
        ok = (valid() & (mktime(&tm_date) != time_t(-1) ) ) ? true : false;
    }
    date(const tm& t) : tm_date(t)
    {
        ok = (mktime(&tm_date) != time_t(-1) ) ? true : false;
    }
// }}}
// p. 162 {{{
    date()
    {
        time_t ltime;
        tm* tm_ptr;
        time(&ltime); // get system time
        tm_ptr= localtime(&ltime); // convert to tm struct
        if ( tm_ptr != NULL )
        {        
            tm_date = *tm_ptr;
            ok = true;
        }        
        else // is date before 1-1-1970
            ok = false;
    }

    bool operator !() //check for the dates validity
    {
        ok = (valid() && (mktime(&tm_date) != time_t(-1) ) ) ? true : false;
        return !ok;
    }

private:
    tm tm_date;
    bool ok;

    bool valid()  // check for sensible date; rejects nonsense like 32.12.1999
                  // The leap - year rule has been simplifies. For example, 1900 wasn't 
                  // a leap year and 2100 won't be.
    {
        if (tm_date.tm_mon < 0 || tm_date.tm_mon > 11) 
            return false;
        if (tm_date.tm_mday < 1)
            switch ( tm_date.tm_mon )
            { 
                case 0 : // !!! sequence was sorted in example
                case 2 :
                case 4 :
                case 6 :
                case 7 :
                case 9 :
                case 11:
                    if (tm_date.tm_mday > 31)
                        return false;
                    break;
                case 1:
                    if (tm_date.tm_mday > 29)
                        return false;
                    if (tm_date.tm_mday > 28 && tm_date.tm_year % 4)
                        return false;
                    break;
              default:  
                  if (tm_date.tm_mday > 30)
                      return false;
            }  
        return true;
    }

    template<class charT, class Traits>
    friend basic_istream<charT, Traits>&
    operator>> (basic_istream<charT, Traits>& is, date& dat);

    template<class charT, class Traits>
    friend basic_ostream<charT, Traits>&
    operator<< (basic_ostream<charT, Traits>& os, const date& dat);
};
// }}}

// p. 163 {{{
// The extractor:
template <class charT, class Traits>
basic_istream<charT, Traits>&
operator >>(basic_istream<charT, Traits>& is, date& dat)
{
    if (!is.good() )
        return is;

    ios_base::iostate err = ios_base::goodbit;
    try 
    {
        typename basic_istream<charT, Traits>::sentry ipfx(is);
        if ( ipfx )
        {        
            use_facet<time_get<charT, istreambuf_iterator<charT, Traits> > >
				(is.getloc()).get_date
					(is, istreambuf_iterator<charT, Traits>(), is, err, &dat.tm_date);
            // check for the date's validity
            if (!dat)
                err |= ios_base::failbit;
        }        
    }
    catch(bad_alloc&)
    {
        err |= ios_base::badbit;
        ios_base::iostate exception_mask = is.exceptions();

        if (    (exception_mask & ios_base::failbit)
            && !(exception_mask & ios_base::badbit ) )
        {
            is.setstate(err);
        }
        else if ( exception_mask& ios_base::badbit) 
        {        
            try {is.setstate(err); }
            catch (ios_base::failure& ) { }
            throw;
        }        
    }
    catch(...)
    {
        err |= ios_base::failbit;
        ios_base::iostate exception_mask = is.exceptions();
// }}}
// p. 164 {{{
        if (   (exception_mask & ios_base::badbit)
            && (err & ios_base::badbit ) )
        {
            is.setstate(err);
        }
        else if(exception_mask & ios_base::failbit)
        {
            try {is.setstate(err); }
            catch( ios_base::failure& ) { }
            throw;
        }
    }

    if (err)
        is.setstate(err);
    return is;
}

// The inserter
template<class charT, class Traits>
basic_ostream<charT, Traits>&
operator<< (basic_ostream<charT, Traits>& os, const date& dat)
{
    if (!os.good() )
        return os;

    ios_base::iostate err = ios_base::goodbit;
    try
    {
        typename basic_ostream<charT, Traits>::sentry opfx(os);
        if (opfx)
        {
            basic_stringbuf<charT, Traits> sb;

			if (use_facet<time_put<charT, ostreambuf_iterator<charT, Traits> > >
				(os.getloc()).put(&sb,os,os.fill(),&dat.tm_date,'x').failed()
			   )
               // set the stream state after checking the return iterator
               err = ios_base::badbit;

            // field width adjustment
            if ( err == ios_base::goodbit )
            {        
                basic_string<charT, Traits> s = sb.str();
                streamsize charToPad = static_cast<streamsize>(os.width() - s.length());
                ostreambuf_iterator<charT, Traits> sink(os);
// }}}
// p. 165 {{{
                if ( charToPad <= 0 )
                {        
                    sink = copy(s.begin(), s.end(), sink);
                }        
                else
                {
                    if (os.flags() & ios_base::left)
                    {
                        sink = copy(s.begin(), s.end(), sink);
                        fill_n(sink, charToPad, os.fill() );
                    }
                    else
                    {
                        fill_n(sink, charToPad, os.fill() );
                        sink = copy(s.begin(), s.end(), sink);
                        
                    }        
                }
                
                if (sink.failed() )
                    err = ios_base::failbit;
            }        
            os.width(0);
        }
    }

    // error handling
    catch (bad_alloc&)
    {
        err |= ios_base::badbit;
        ios_base::iostate exception_mask = os.exceptions();

        if (    ( exception_mask & ios_base::failbit)
            && !( exception_mask & ios_base::badbit ) )
        {        
            os.setstate(err);
        }        
        else if (exception_mask & ios_base::badbit)
        {
            try { os.setstate(err); }
            catch( ios_base::failure& ) { }
            throw;
        }        
    }

    catch(...)
    {
        err |= ios_base::failbit;
        ios_base::iostate exception_mask = os.exceptions();
// }}}
// p. 166 {{{
        if(    (exception_mask & ios_base::badbit)
            && (err & ios_base::badbit) )
        {
            os.setstate(err);
        }
        else if ( exception_mask & ios_base::failbit )
        {        
            try { os.setstate (err ); }
            catch( ios_base::failure& ) { }
            throw;
        }        
    }

    if (err) 
        os.setstate( err );
    return os;
}
// }}}

#endif