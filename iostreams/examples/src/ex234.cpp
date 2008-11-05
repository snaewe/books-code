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

#include <io.h>
#include <streambuf>
#include <iostream>

#include <string>

using namespace ::std;

#include "char_x_device_229.h"
#include "unbuffered_streambuf_230.h"

int main()
{
	// p. 234 {{{
    unbuffered_streambuf<char, char_traits<char> > mybuf;
    iostream mystream(&mybuf);

    cout << "Test Begin !!!" << endl;

    mystream << "Hello World !" << endl;

    // Test extracting numeric value
    cout << "Type in an integer: ";
    int testInt = 0;
	mystream >> testInt;
    if (!mystream)
        cout << "Error: " << mystream.rdstate() << endl;
    mystream << "Echo: " << testInt << endl;
    mystream.clear();

    // Test extracting character sequence
    cout << "Type in a character: ";
    char testChar = '\0';
	mystream >> testChar;
    if (!mystream)
        cout << "Error: " << mystream.rdstate() << endl;
    mystream << "Echo: " << testChar << endl;
    mystream.clear();
// }}}
// p. 235 {{{
    // Test: unformatted input
    cout << "Type in a character: ";
    char testC = '\0';
    mystream.get(testC);
    if (!mystream)
        cout << "Error: " << mystream.rdstate() << endl;
    mystream << "Echo: " << testC << endl;
    mystream.clear();

    cout << "test End !!!" << endl;
    return 0;
}
// }}}
/* Input / Output: There is a problem with the input. Your input is not evaluated until you press enter. Therefore
it is the best you enter a whole line of all input and press enter. E. g.:

1234ab
yields to the screen shot:

Test Begin !!!
Hello World !
Type in an integer: 123ab
Echo: 123
Type in a character: Echo: a
Type in a character: Echo: b
test End !!!

To produce errors type (^z means ctrl + z)
a^Z^Z

yields to:

Test Begin !!!
Hello World !
Type in an integer: a^Z^Z
Error: 2
Type in a character: Echo: a
Type in a character: Error: 3
test End !!!

*/
