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
#include <string>
#include <cassert>

using namespace ::std;

int main()
{
    {
       // The statement 
       // fstream fstr("filnam.txt", ios_base::in | ios_base::out );
       // does not enforce the existence of a file
       // Therefore the existence of an empty file is enforced by this block.
       fstream fstr("filnam.txt", ios_base::out );
    }
	
	// p. 53 {{{
    fstream fstr("filnam.txt", ios_base::in | ios_base::out);

    //...do some output to the file stream ...
    fstr << "0123456789" << endl; // !!! for example

    // reset the joint file position to the begin of the file stream
    fstr.seekg(0, ios_base::beg);

    // ... read from the file stream ...
	// }}}

    const int buffer_size = 100;
    char buffer[buffer_size];
	// p. 53 {{{
    fstr.read(buffer, 5);
	// }}}
    assert(0 == strncmp(buffer, "01234", 5) ); 

    // move the joint streamposition 3 positions back
    fstr.seekp(-3, ios_base::cur);

	// p. 53 {{{
    // ...write to the current stream position ...
	// }}}
    char outbuf1[] = "ABC";
    fstr.write(outbuf1,3);
    // File contents should be "01ABC56789"

	// p. 53 {{{
    // memorize the current joint stream position for later use
    fstream::pos_type pos =fstr.tellg();

    // ... write to the file stream ...
	// }}}
    char outbuf2[] = "DEF";
    fstr.write(outbuf2,3);
    // File contents should be "01ABCDEF89"

	// p. 53 {{{
    // reposition to a location 2 positions after the previously memorized position
    fstr.seekg(pos + fstream::off_type(2) );
	// }}}
    char outbuf3[] = "#*";
    fstr.write(outbuf3,2);
    // File contents should be "01ABCDE#*9"

    // Final test if file contents really is "01ABCDE#*9"
    string s;
    fstr.seekg(0, ios_base::beg);
    fstr >> s;
    assert ( "01ABCDE#*9"== s );

    return 0;
}

/* Input: No input
*/
/* Output: No output
*/