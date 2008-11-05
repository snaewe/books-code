/*
author:  "Klaus Wittlich" <Klaus_Wittlich@sae.de> 

Based on source code published in the book "Standard C++ IOStreams 
and Locales" by Angelika Langer & Klaus Kreft, Copyright (c) 2000 by 
Addison Wesley Longman, Inc.

Permission to use, copy, and modify this software for any non-profit
purpose is hereby granted without fee.  Neither the author of this 
source code, Klaus Wittlich, nor the authors of the above mentioned 
book, Angelika Langer and Klaus Kreft, nor the publisher, Addison Wesley 
Longman, Inc., make any representations about the suitability of this 
software for any purpose.  It is provided "as is" without express or 
implied warranty.
*/

#include <fstream>
#include <iostream>

using namespace ::std;

int main()
{
	// p.45 {{{
    fstream fstr("test2.txt", ios_base::in | ios_base::out);
    char buf[32]; buf[31] = '\0';
    char puf[] = "hello world";

    // write output to the file stream
    fstr << puf;
    if (!fstr.good() )
        cout << "stream status (1): " << fstr.rdstate() << endl;
	// }}}
	// p. 46 {{{
    //reposition to the begin of the file stream
    fstr.seekg(0, ios_base::beg);
    if (!fstr.good() )
        cout << "stream status (2): " << fstr.rdstate() << endl;

    // read input from the file stream
    fstr.get(buf, sizeof(buf) - 1);
    if (!fstr.good() )
        cout << "stream status (3): " << fstr.rdstate() << endl;
	// }}}

    return 0;
}

/* Output: If test2.txt exists and ist size is less than sizeof(buf) - 1: 
stream status (3): 1
// Contents from test2.txt changes e. g. from
01234567890123456789
// to 
hello world123456789
*/
/* Output: If test2.txt exists and ist size is not less than sizeof(buf) - 1: No Output
// Contents from test2.txt changes e. g. from
0123456789012345678901234567890123456789
// to 
hello world12345678901234567890123456789
*/
/* Output: If test2.txt dos not exist:
stream status (1): 6
stream status (2): 6
stream status (3): 6
// test2.txt will not be created.
*/
