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
#include "unbuffered_streambuf_230.h"
*/

#ifndef UNBUFFERED_STREAMBUF_H
#define UNBUFFERED_STREAMBUF_H

// p. 230 {{{
// !!! Protected methods are inline. Otherwise the protected virtual methods result in unresolved externals.
template <class charT, class traits>
class unbuffered_streambuf : public basic_streambuf<charT, traits>
{
    public:
        unbuffered_streambuf() : takeFromBuf(false) {}

    protected:

		int_type overflow(int_type c = traits_type::eof() )
		// p. 231 {{{
		{
			if (!traits_type::eq_int_type(c, traits_type::eof()))
			{
				if (char_to_device(traits_type::to_char_type(c)) < 0 )
					return traits_type::eof();
				else
					return c;
			}

			return traits_type::not_eof(c);
		}
		// }}}

		int_type uflow()
		// p. 233 {{{
		{
			if ( takeFromBuf )
			{        
				takeFromBuf = false;
				return traits_type::to_int_type(charBuf);
			}        
			else
			{
				char_type c;

				if (char_from_device(&c) < 0)
					return traits_type::eof();
				else
				{
					charBuf = c;
					return traits_type::to_int_type(c);
				}        
			}        
		}
		// }}}

        int_type underflow()
		// p. 232 {{{
		{
			if ( takeFromBuf )
			{        
				return traits_type::to_int_type(charBuf);
			}        
			else
			{
				char_type c;

				if (char_from_device(&c) < 0)
					return traits_type::eof();
				else
				{
					takeFromBuf = true;
					charBuf = c;
					return traits_type::to_int_type(c);
				}
			}        
		}
		// }}}
		
		int_type pbackfail(int_type c)
		// p. 233 {{{
		{
			if ( !takeFromBuf )
			{     
				if (!traits_type::eq_int_type(c, traits_type::eof()))
					charBuf = traits_type::to_char_type(c);

				takeFromBuf = false;
				return traits_type::to_int_type(charBuf);
			}        
			else
			{
				return traits_type::eof();
			}        
		}
		// }}}

    private:
        char_type charBuf;
        bool takeFromBuf;

        // prohibit copying and assingment
        unbuffered_streambuf(const unbuffered_streambuf&);
        unbuffered_streambuf& operator = (const unbuffered_streambuf&);
};





#endif