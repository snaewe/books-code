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
#include <cassert>

using namespace ::std;

// In this example the input is "A". Therefore the input should be checked.
template <class charT>
void f(charT c)
{
    assert('A' == c);
}

// p. 115 {{{
template <class charT, class Traits> 
void foo(basic_streambuf<charT,Traits>* sbuf) 
{ 
  Traits::char_type c; 
  Traits::int_type i; 
  i = sbuf->sgetc();      // get the next value 
                          // see whether it’s end-of-file 
  if (!Traits::eq_int_type(i,Traits::eof()))  
                          // if not, convert it to a character 
  { c = Traits::to_char_type(i);  
//    ...                   // pass on the character 
    f(c); // !!!  for example reasons doing anything
  } 
} 
// }}}

int main()
{
    basic_streambuf<char> * bp1 = cin.rdbuf();

    foo(bp1);

    return 0;
}

/* Input: (Do not forget to press Enter)
A
*/
/* Output: No output
*/
