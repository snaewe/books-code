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
#include "date_170.h"
*/

#ifndef DATE_H
#define DATE_H

// p. 173 {{{
class date {
public:
    date(int d, int m, int y);
    date(const tm& t);
    date()
	// p. 162 {{{
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
    bool operator !()
    {
        ok = (valid() && (mktime(&tm_date) != time_t(-1) ) ) ? true : false;
        return !ok;
    }
	// }}}

    template <class charT, class Traits>
        ios_base::iostate get_from(basic_istream<charT, Traits>& is)
    {
        ios_base::iostate err = 0;
        use_facet<time_get<charT, istreambuf_iterator<charT, Traits> > > (is.getloc()).get_date
            (is, istreambuf_iterator<char, char_traits<char> > (), is, err, &tm_date);
        if (!(*this) || err)
            return ios_base::failbit;
        else
            return ios_base::goodbit;
    }

    template <class charT, class Traits>
        ios_base::iostate print_on(basic_ostream<charT, Traits>& os) const
    {
        const char * const patt = "%x";
        char fmt[3];
        basic_stringbuf<charT, Traits> sb;
        ios_base::iostate err = 0;

        use_facet<ctype<charT> > (os.getloc()).widen(patt, patt+2, fmt);
        if (     use_facet<time_put<charT, ostreambuf_iterator<charT, Traits> > >
             (os.getloc()).put(&sb, os, os.fill(), &tm_date, fmt, (fmt+2)).failed()
           )
           err = ios_base::failbit;
        if ( err == ios_base::goodbit )
        {        
            basic_string<charT, Traits> s = sb.str();
            streamsize charToPad = static_cast<streamsize> (os.width() - s.length());
            ostreambuf_iterator<charT, Traits> sink(os);
            if (charToPad <= 0)
                sink = copy(s.begin(), s.end(), sink);
// }}}
// p. 174 {{{
            else 
            {
                if ( os.flags() & ios_base::left )
                {
                    sink = copy(s.begin(), s.end(), sink);
                    fill_n(sink, charToPad, os.fill() );
                }
                else
                {
                    fill_n(sink, charToPad, os.fill());
                    sink = copy(s.begin(), s.end(), sink);
                }
            }
            if (sink.failed() )
                err = ios_base::failbit;
        }
        return err;
    }
private:
    tm tm_date;
    bool ok;
// p. 162
    bool valid()  // check for sensible date; rejects nonsense like 32.12.1999
                  // The leap - year rule has been simplifies. For example, 1900 wasn't 
                  // a leap year and 2100 won't be.
    {
        if (tm_date.tm_mon < 0 || tm_date.tm_mon > 11) 
            return false;
        if (tm_date.tm_mday < 1)
            switch ( tm_date.tm_mon )
            { 
                case 0 : 
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
// }}}
};
// }}}

// p. 170
// The extractor:
template <class charT, class Traits, class Argument>
basic_istream<charT, Traits>& g_extractor
    (basic_istream<charT, Traits>& is, Argument& arg)
{
// }}}
// p. 171 {{{
    ios_base::iostate err = ios_base::goodbit;
    try
    {
        typename basic_istream<charT, Traits>::sentry ipfx(is);
        if ( ipfx )
            err = arg.get_from(is);
    }
    catch(bad_alloc&)
    {
        err |= ios_base::badbit;
        ios_base::iostate exception_mask = is.exceptions();
        if(     (exception_mask & ios_base::failbit)
            && !(exception_mask & ios_base::badbit ))
        {
            is.setstate(err);
        }
        else if ( exception_mask & ios_base::badbit )
        {        
            try { is.setstate(err); }
            catch (ios_base::failure& ) {}
            throw;
        }        
    }
    catch(...)
        {
        err |= ios_base::failbit;
        ios_base::iostate exception_mask = is.exceptions();
        if (    (exception_mask & ios_base::badbit)
            && (err & ios_base::badbit) )
        {
            is.setstate(err);
        }
        else if ( exception_mask & ios_base::failbit )
        {        
            try { is.setstate(err); }
            catch( ios_base::failure& ) { }
            throw;
        }        
    }

    if ( err ) is.setstate( err );
    return is;
}

// The inserter:
template <class charT, class Traits, class Argument> 
basic_ostream<charT, Traits>& g_inserter  
  (basic_ostream<charT, Traits>& os, const Argument& arg) 
{
    ios_base::iostate err = 0;
    try
    {
        typename basic_ostream<charT, Traits>::sentry opfx(os);
        if ( opfx )
        {        
            err = arg.print_on(os);
            os.width(0);
        }        
    }
// }}}
// p. 172 {{{
    catch(bad_alloc&)
    {
        err |= ios_base::badbit;
        ios_base::iostate exception_mask = os.exceptions();
        if (    (exception_mask & ios_base::failbit)
            &&! (exception_mask & ios_base::badbit) )
        {        
            os.setstate (err);
        }        
        else if (exception_mask & ios_base::badbit)
        {
            try { os.setstate( err ); }
            catch (ios_base::failure& ) { }
            throw;
        }
    }
    catch(...)
    {
        err |= ios_base::failbit;
        ios_base::iostate exception_mask = os.exceptions();
        if (    (exception_mask & ios_base::badbit )
            &&  (err & ios_base::badbit))
        {        
            os.setstate( err );
        }        
        else if ( exception_mask & ios_base::failbit )
        {        
            try { os.setstate( err ); }
            catch( ios_base::failure& ) { }
            throw;
        }        
    }
    if (err )
        os.setstate( err );
    return os;
}
// }}}

// p. 170 {{{
template <class charT, class Traits>
basic_istream<charT, Traits>& operator >>
    (basic_istream<charT, Traits> &is, date& arg)
{
    if (!is.good())
        return is;
    return g_extractor(is, arg);
}

template <class charT, class Traits>
basic_ostream<charT, Traits>& operator <<
    (basic_ostream<charT, Traits>& os, const date& arg)
{
    if (!os.good() )
        return os;
    return g_inserter(os, arg);
}
// }}}

#endif