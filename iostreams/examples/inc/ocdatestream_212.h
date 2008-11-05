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
#include "ocdatestream_212.h"
*/

#ifndef CONCRETEOSTREAM_H
#define CONCRETEOSTREAM_H

#include "datefmt_210.h"

// p. 212 {{{
template <class ConcreteOStream>
class ocdatestream
: public ConcreteOStream, public datefmt<typename ConcreteOStream::char_type>
{
    public:
        typedef typename ConcreteOStream::char_type char_type;

		ocdatestream (const char *s, ios_base::openmode mode, const char_type * fmt) // !!! different: in book fmt = 0;
            : ConcreteOStream(s, mode),
              datefmt<char_type>(fmt)
        { }

        // ...
};
// }}}

#endif