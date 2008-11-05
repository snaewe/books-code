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
#include "one_arg_manip_weh_187.h"
*/

#ifndef ONE_ARG_MANIP_WEH
#define ONE_ARG_MANIP_WEH

// p. 187 {{{
template <class Argument>
class one_arg_manip_weh
{
    public:
        typedef void (* manipFct)(ios_base&, Argument);
        one_arg_manip_weh(manipFct pf, const Argument& arg)
            : pf_(pf), arg_(arg), error_(ios_base::goodbit) {}

    protected:
        void setFail() {
            error_ |= ios_base::failbit;
        }
        void setBad()  {
            error_ |= ios_base::badbit;
        }

    private:
        manipFct pf_;
        const Argument arg_;
        ios_base::iostate error_;

		template <class charT, class Traits, class Argument>
        friend void do_manip
        (basic_ios<charT, Traits>& str, const one_arg_manip_weh<Argument>& oamw);
};
// }}}

// p. 188 {{{
template <class charT, class Traits, class Argument> 
basic_ostream<charT,Traits>& operator<<  
(basic_ostream<charT,Traits>& os,  
const one_arg_manip_weh<Argument>& oamw) 
{ 
	if(os.good()) 
		do_manip(os,oamw); 
	return os; 
} 

template <class charT, class Traits, class Argument>
		void do_manip(basic_ios<charT, Traits>& str, 
		const one_arg_manip_weh<Argument>& oamw)
{
	if (oamw.error_ != ios_base::goodbit)
		str.setstate(oamw.error_);
	else 
	{
		ios_base::iostate err = oamw.error_;
		try { 
			(*(oamw.pf_))(str, oamw.arg_); 
		}
		catch(bad_alloc&)
		{
			err |= ios_base::badbit;
			ios_base::iostate exception_mask = str.exceptions();
// }}}
// p. 189 {{{
			if (   (exception_mask & ios_base::failbit)
				    &&(exception_mask & ios_base::badbit))
			{       
				str.setstate(err);
			}       
			else if ( exception_mask & ios_base::badbit )
			{       
				try {str.setstate(err); }
				catch (ios_base::failure&) { }
				throw;
			}       
		}
		catch(...)
		{
			err |= ios_base::failbit;
			ios_base::iostate exception_mask = str.exceptions();
			if (   ( exception_mask & ios_base::badbit)
					&&( err & ios_base::badbit) )
			{       
				str.setstate(err);
			}       
			else if ( exception_mask & ios_base::failbit )
			{       
				try {
					str.setstate(err);
				}
				catch (ios_base::failure& ) { }
				throw;
			}       
		}
		if (err)
			str.setstate(err);
	}
}
// }}}


#endif