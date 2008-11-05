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

// We need a process function for example
void process(float f)
{
    static int count = 0;
    ++count;
    cerr << "process times called: " << count << endl;
}

// We need an error function for example
void error() 
{
    cerr << "An error has occured" << endl;
}


int main()
{
	// p. 29 {{{
	//*
    cin >> noskipws;
	//*/
    char c;
    do {
        float f1;
        c = ' ';                        // clear character
        cin >> f1 >> c;                 // extract number and seperator
        if ( c == ',' || c == '\n' )    // next char is ',' or newline
            process(f1);                // yes: use the number
    } while (c == ',');

    if (c != '\n') error();             // no: error!
	// }}}

    return 0;
}

// Examples with cin >> noskipws;

/* Input 1: Without white spaces at the end (Enter return after input)
3.141592653589793238462,2.718281828459045235360287471352
*/
/* Output 1:
process times called: 1
process times called: 2
*/

/* Input 2: With some white spaces at the end (Enter return after input)
3.141592653589793238462,2.718281828459045235360287471352     
*/
/* Output 2:
process times called: 1
An error has occured
*/


// Exapmples without cin >> noskipws;
// Both inputs above lead to the same behaviour.
// "process times called: 1" is displayed. If you type one ore more times enter the cursor 
// moves down. If you type something followed by enter "An error has occured" is displayed.
// If that something you enter is a "," "process times called: 2" will be displayed before
// "An error has occured" is displayed.
