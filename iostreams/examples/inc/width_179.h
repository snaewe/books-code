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
#include "width_179.h"
*/

#ifndef WIDTH_H
#define WIDTH_H

// p. 179 {{{
class width {
public:
    explicit width(unsigned int i) : i_(i) {}
private:
    unsigned int i_;

public:
    template <class charT, class Traits>
    friend basic_ostream<charT, Traits>& operator <<
    (basic_ostream<charT, Traits>& ib, const width& w)
    {
        // the manipulation: set the stream's width
        ib.width(w.i_);
        return ib;
    }
};
// }}}


#endif