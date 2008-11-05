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
// If files src.cpp and dst.cpp do not exist they are createtd.
// If files src.cpp and dst.cpp exist they are overwritten.


#include <fstream>

using namespace ::std;

int main()
{
	// p. 40 {{{
	{
		ofstream fil("src.cpp"); // file is implicitly opened at construction time
		//...
		if (fil.is_open() )
			fil.close();

		fil.open("dst.cpp");  // connect to an other file
							// fil goes out of scope here and is automatically
							// closed 
	}
	// }}}

    return 0;
}

/* Output: no output
*/
