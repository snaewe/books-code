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
#include "mendl_180.h"
*/

#ifndef MENDL_H
#define MENDL_H

// p. 180 {{{
class mendl { 
public: 
    explicit mendl(unsigned int i) : i_(i) {} 
private: 
    unsigned int i_; 
    
public:
    template <class charT, class Traits> 
    friend 
        basic_ostream<charT,Traits>& operator<<  
        (basic_ostream<charT,Traits>& os, const mendl& w) 
    {  
        // the manipulation: insert end-of-line characters and flush 
        for (unsigned int i=0; i<w.i_;  i++) 
            os.put(os.widen('\n'));  
        return os.flush(); 
    } 
}; 
// }}}

#endif