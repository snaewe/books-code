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

// Annotation
// If files exist they remain untouched
// If files do not exist only out.txt will be created

#include <fstream>

using namespace ::std;

int main()
{
	// p. 45 {{{
    // bidirectional file stream opened only for input
    fstream BiFil("poem.txt", ios_base::in);

    // bidirectional file stream opened only for output
    fstream OutFil("out.txt", ios_base::out | ios_base::app);
	// }}}

    return 0;
}

/* Output: no output
*/
