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

using namespace ::std;

int main()
{
	// p. 49 {{{
    // character buffer; can store lines of length 99
    // note: input adds a terminating null character
    const int line_buffer_size = 100;
    char buffer[line_buffer_size];
	// }}}
	// p. 50 {{{
    int line_number = 0;
    while (   cin.getline(buffer, line_buffer_size, '\n') // stream still good() ?
           || cin.gcount() )                              // any characters read?
    {     
        int count = cin.gcount(); 

        if ( cin.eof() )
            // end of file found; last line extracted
            cout << "Partial final line";
        else if(cin.fail() )
        {
            // max number of chars was reached; line was longer than 99 chars
            cout << "Partial long line";
            // clear stream state so that we can continue reading
            cin.clear(cin.rdstate() & ~ios::failbit);
        } else {
            // dont't include newline in count
            // mind: delimiter was extracted and counted, but not stored
            --count;
            cout << "Line " << ++line_number;
        }

        cout << " (" << count << " chars): " << buffer << endl;
    }     
	// }}}

    return 0;
}

/* Input: use ex049.in. Call ex049.exe < ex049.in. This for ^Z has not in all cases the desired effect on the keyboard.
* The contents of ex049.in is:
A234567890B234567890C234567890D234567890E234567890F234567890
A234567890B234567890C234567890D234567890E234567890F234567890G234567890H234567890I234567890J234567890K234567890L234567890M234567890
A234567890B234567890C234567890D234567890E234567890F234567890
*/
/* Output: 
Line 1 (60 chars): A234567890B234567890C234567890D234567890E234567890F234567890
Partial long line (99 chars): A234567890B234567890C234567890D234567890E234567890F234567890G234
567890H234567890I234567890J23456789
Line 2 (31 chars): 0K234567890L234567890M234567890
Partial final line (60 chars): A234567890B234567890C234567890D234567890E234567890F234567890
*/