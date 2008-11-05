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

#include <iostream>
#include <limits>

using namespace ::std;

void process(float f)
{
    static int count = 0;
    ++count;
    cerr << "process called " << count << " times" << endl;
}

int main()
{
    float f;

	// p. 29 {{{
    cin.ignore (numeric_limits<streamsize>::max(), '\n');
	// }}}

    cin >> f;
    process(f);

	// p.30 {{{
    wcin.ignore(numeric_limits<streamsize>::max(), wchar_t('\n') );
	// }}}
    wcin >> f;
    process(f);

    return 0;
}

/* Input:


1.23


4.56
*/
/* Output: (what you see on the screen)


1.23
process called 1 times


4.56
process called 2 times
*/
