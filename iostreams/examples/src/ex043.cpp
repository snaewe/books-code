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
// The default arguments in ctor of fstream are slight different from book,
// flag trunc is missing. Therefore the behavior is different from book's description.
// case 1: 
//		poem.txt does not exist --> empty poem.txt will be created
//		poem.txt exists --> empty poem.txt will be cleared
// case 2:
//		poem.txt does not exist --> file will be cleared.
//		poem.txt exists --> remains untouched



#include <fstream>

using namespace ::std;

int main()
{
    /* // case 1
	// p. 43 {{{
    fstream BiStr("poem.txt", ios_base::in | ios_base::out | ios_base::trunc);
	// }}}
    /*/ // case 2
	// p. 44 {{{
    fstream BiStr("poem.txt");
	// }}}
    //*/

    return 0;
}

/* Output: no output
*/
