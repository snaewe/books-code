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
#include "datefmt_210.h"
*/

#ifndef DATEFMT_H
#define DATEFMT_H

// p. 210 {{{
template <class charT>
class datefmt
{
    public:
        datefmt(const charT* f) : myFmt(f) { }

		virtual void fmt(const charT* f)
		{ 
			myFmt = f; 
		}

        virtual const basic_string<charT>& fmt() const
        {
            return myFmt;
        }

        virtual ~datefmt() {}
    private:
        basic_string<charT> myFmt;
};
// }}}

#endif