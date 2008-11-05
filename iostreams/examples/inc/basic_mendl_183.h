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
#include "basic_mendl_183.h"
*/

#ifndef BASIC_MENDL_H
#define BASIC_MENDL_H

#include "one_arg_manip_183.h"

// In the book p. 183 the class is named mendl, but later on top of p. 184 
// it should be renamed to basic_mendl.
// p. 183 {{{
template <class charT, class Traits = char_traits<charT> >
class basic_mendl : public one_arg_manip<charT, Traits, unsigned int> // !!! basic_mendl instead of mendl
{
public:
    explicit basic_mendl(unsigned int i) // !!! basic_mendl instead of mendl
        : one_arg_manip<charT, Traits, unsigned int>(basic_mendl::fct, i) // !!! basic_mendl instead of mendl
    {}
private:
    static void fct(basic_ostream<charT, Traits>& os, unsigned int n)
    {
        for ( int i=0; i<n; ++i )
            os.put(os.widen('\n'));
        os.flush();
    }
};
// }}}

#endif