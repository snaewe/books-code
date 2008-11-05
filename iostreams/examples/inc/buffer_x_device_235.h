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
#include "buffer_x_device_235.h"
*/

#ifndef BUFFER_X_DEVICE_H
#define BUFFER_X_DEVICE_H

// p. 235 {{{
int buffer_to_device (const char * c, int n)
{
    if (_write(1,c,n) != n)
        return -1;
    else
        return 0;
}

int buffer_from_device(char * c, int n)
{
    return _read(0, c, n);
}
// }}}

#endif