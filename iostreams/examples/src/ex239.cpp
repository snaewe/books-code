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
#include "inbuf_239.h"

// p. 242 {{{
int main()
{
    inbuf<char, char_traits<char> > mybuf;
    istream mystream(&mybuf);
    int testInt = 0;

    cout << "Test Begin !!! - type in an integer: " << endl;
// }}}
// p. 243 {{{
    mystream >> testInt;

    if (!mystream)
        cout << "Error: " << mystream.rdstate() << endl;
    else
        cout << "Echo: " << testInt << endl;

    mystream.putback('3');

    mystream >> testInt;

    if (!mystream)
        cout << "Error: " << mystream.rdstate() << endl;
    else
        cout << "Echo: " << testInt << endl;

    cout << "Test End !!!" << endl;

    return 0;
}
// }}}

/* Input "30" yields to screenshot:
Test Begin !!! - type in an integer:
30
Echo: 30
Echo: 3
Test End !!!
*/
/* Input "abc" yields to screenshot:
Test Begin !!! - type in an integer:
abc
Error: 2
Error: 2
Test End !!!
*/
