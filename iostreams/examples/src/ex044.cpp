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

// Annotation:
// If files do not exit, out.txt is created as empty file.
// If files exit, they remain untouched.

#include <fstream>

using namespace ::std;

int main()
{
    //*
	// p. 44 {{{
    ofstream OStr("out.txt", ios_base::out | ios_base::app);
    ifstream IStr("in.txt" , ios_base::in  | ios_base::binary);
	// }}}
    /*/
	// p. 44 {{{
    ofstream OStr("out.txt", ios_base::app);
    ifstream IStr("in.txt" , ios_base::binary);
	// }}}
    //*/

    return 0;
}

/* Output: no output
*/
