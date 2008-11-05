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
#include "one_arg_manip_183.h""
*/

#ifndef ONE_ARG_MANIP_H
#define ONE_ARG_MANIP_H

// modified version for p. 183
// one_arg_manip from page 181 has only one template argument, class Argument and deals with
// ios_base. This version deals with basic_ostream<charT, Traits> instead of ios_base
// p. 181 {{{
template <class charT, class Traits, class Argument> // !!! More template arguments
class one_arg_manip
{
public:
    typedef void (* manipFct)(basic_ostream<charT, Traits>&, Argument); // !!! basic_ostream instead of ios_base
    one_arg_manip(manipFct pf, const Argument& arg)
        : pf_(pf), arg_(arg) {}

private:
    manipFct pf_;
    const Argument arg_;

	// !!! line template <...> left out
    friend basic_istream<charT, Traits>& operator >>
    (basic_istream<charT, Traits>& is, const one_arg_manip<charT, Traits, Argument>& oam)
    {
        if (!is.good() )
            return is;
        (*(oam.pf_))(is, oam.arg_);
        return is;
    }

	// !!! line template <...> left out
    friend basic_ostream<charT, Traits>& operator <<
    (basic_ostream<charT, Traits>& os, const one_arg_manip<charT, Traits, Argument>& oam) // one_arg_manip with template parameters
    {
        if (!os.good())
            return os;  
        (*(oam.pf_))(os,oam.arg_);
        return os;
    }
};
// }}}

#endif