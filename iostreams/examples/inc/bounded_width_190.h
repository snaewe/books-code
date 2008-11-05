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
#include "bounded_width_190.h"
*/

#ifndef BOUNDED_WIDTH
#define BOUNDED_WIDTH

#include "one_arg_manip_190.h"

// p. 190 {{{
class bounded_width : public one_arg_manip<unsigned int>
{
public:
    bounded_width(unsigned int min, unsigned int max)
		: one_arg_manip<unsigned int>(bounded_width::fct, min),
        min_(min), max_(max) {}

    one_arg_manip<unsigned int>& operator() (unsigned int i)
    {
        if (i < min_)
            arg_ = min_;
        else if (i > max_)
            arg_ = max_;
        else 
            arg_ = i;
        return *this;
    }
private:
    static ios_base& fct(ios_base& ib, unsigned int i)
    {
        ib.width(i);
        return ib;
    }

    unsigned int min_;
    unsigned int max_;
};
// }}}

#endif