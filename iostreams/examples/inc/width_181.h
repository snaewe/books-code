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
#include "width_181.h"
*/

#ifndef WIDTH_H
#define WIDTH_H

// p. 181 {{{
class width : public one_arg_manip<unsigned int>
{
public:
    explicit width(unsigned int i) : one_arg_manip<unsigned int>(width::fct, i)
    { }
private:
    static void fct (ios_base& ib, unsigned int i)
    {
        ib.width(i);
    }
};
// }}}
#endif