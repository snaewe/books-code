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
	// p. 46 {{{
    fstream fstr("test1.txt", ios_base::in | ios_base::out);
    char buf[32]; buf[31] = '\0';
    char puf[] = "hello world";

    // read form the file stream
    fstr.get(buf, sizeof(buf) - 1);
    if ( !fstr.good() )
    {        
        cout << "stream status (1): " << fstr.rdstate() << endl;
        if (fstr.eof() )
            fstr.clear(); // needed to allow subsequent output
    }        
	// }}}
	// p. 47 {{{
    // write to the file stream 
    fstr << puf;
    if (!fstr.good() )
        cout << "stream status (2): " << fstr.rdstate() << endl;
	// }}}

    return 0;
}

/* Output: If test1.txt exists and its size is less than sizeof(buf) - 1: 
stream status (2): 4
*/
/* Output: If test1.txt exists and ist size is not less than sizeof(buf) - 1: No Output
*/
/* Output: If test1.txt dos not exist:
stream status (1): 2
stream status (2): 6
*/
