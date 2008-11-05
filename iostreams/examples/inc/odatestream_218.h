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
#include "odatestream_218.h"
*/

#ifndef ODATESTREAM_H
#define ODATESTREAM_H

#include "datefmt_210.h"
#include "defaultpatt_197.h"

// Implementation of functions is taken from p. 216 and 217. The compiler does not accept the other way.

// p. 215 {{{
template <class OStream>
class odatestream
: public OStream, public datefmt<typename OStream::char_type>
{
    public:
        typedef typename OStream::char_type char_type;

		// !!! ctor implemented inline for the compiler does not accept the try statement otherwise
        odatestream(const char_type* s, ios_base::openmode mode
			, const char_type * fmt = 0)
		// p. 216 {{{
		try 
			: OStream(s, mode), datefmt<char_type>(fmt? fmt : dafaultPatt(*this)) { }
		catch (...) 
			{ setbad(); }
		// }}}

		// !!! ctor implemented inline for the compiler does not accept the try statement otherwise
		odatestream(const OStream& toBeAdapted, const char_type * fmt = 0)
		// p. 216 {{{
			try
			: OStream(toBeAdapted.rdbuf())
			, datefmt<char_type>(fmt ? fmt : defaultPatt(toBeAdapted).c_str() )
		{
			clear(toBeAdapted.rdstate());
			copyfmt(toBeAdapted);
		}
		catch(...) {setbad(); }
		// }}}

		// ...
		void setbad();					// !!! Not mentioned in class definietion, but implemented p. 217
		void fmt(const char_type* f);	// !!! Not mentioned in class definietion, but implemented p. 218
}; 
// }}}

// p. 217 {{{
template <class OStream>
void odatestream<OStream>::setbad()
{
	if ( exceptions() & ios_base::badbit )
	{        
		try { setstate(ios_base::badbit | rdstate()); }
		catch( ios_base::failure&) {}
		throw;
	}        
	else
	{
		setstate(ios_base::badbit | rdstate() );
	}        
}
// }}}

// p. 218 {{{
template <class OStream>
void odatestream<OStream>::fmt(const char_type* f)
{
	try { datefmt<char_type>::fmt(f); }
	catch(...) { setbad(); }
}
// }}}

#endif
