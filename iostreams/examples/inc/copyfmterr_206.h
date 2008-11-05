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
#include "copyfmterr_206.h"
*/

#ifndef COPYFMTERR_H
#define COPYFMTERR_H

// p. 206 {{{
template <class charT, class Traits>
ios_base::iostate copyfmtErr(basic_ios<charT, Traits>& os)
{
    ios_base::iostate err = static_cast<ios_base::iostate> (os.iword(getIdx()));
    os.iword(getIdx()) = 0L;
    os.setstate(err | os.rdstate());
    return err;
}
// }}}

#endif