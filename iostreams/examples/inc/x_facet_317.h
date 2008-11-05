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
#include "x_facet_317.h"
*/

#ifndef X_FACET_H
#define X_FACET_H

// p. 317 {{{
class base_facet : public locale::facet
{
    // constructors and destructors
public:
    virtual string bar() const {
        return "this is the base class"; 
    }
    static locale::id id;
};

class derived_facet : public base_facet
{
    // constructors and destructors
public:
    virtual string bar() const {
        return "this is the derived class";
    }
    virtual string bar_2() const {
        return "hello world";
    }
};
// }}}

#endif