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
#include "char_x_device_229.h"
*/

#ifndef CHAR_X_DEVICE_H
#define CHAR_X_DEVICE_H

// p. 229 {{{
int char_to_device(char c)
{
    if ( _write(1, &c, 1) != 1 )
        return -1;
// }}}
// p. 230 {{{
    else
        return 0;
}

int char_from_device(char * c)
{
    if (_read(0, c, 1) != 1)
        return -1;
    else
        return 0;
}
// }}}

#endif