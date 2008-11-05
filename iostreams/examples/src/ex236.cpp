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

#include <streambuf>
#include <iostream>
#include <io.h>

using namespace ::std;

#include "buffer_x_device_235.h"
#include "outbuf_236.h"

// p. 239 {{{
int main()
{
    outbuf<char, char_traits<char> > mybuf;
    ostream mystream(&mybuf);

    cout << "Test Begin !!!" << endl;

    mystream << "Hello World !" << endl;
    mystream << "formatting stil works: " << hex << 15 << endl;

    cout << "Test End !!!"  << endl;
    return 0;
}
// }}}

/* Screenshot:
Test Begin !!!
Hello World !
formatting stil works: f
Test End !!!
*/
