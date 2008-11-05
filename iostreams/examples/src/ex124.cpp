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

#include <list>
#include <algorithm>
#include <iostream>

using namespace ::std;

namespace book {

// p. 124 {{{
template <class Iterator, class T>
Iterator find( Iterator first, Iterator end, const T& value)
{
    while (first != end && *first != value)
        ++first;
    return first;
}
// }}}

}

// p. 124 {{{
void foo(list<int>& myList)
{
    //*
    // Using implementation of book
    if (book::find(myList.begin(), myList.end(), 0) != myList.end() ) // !!! book::find instead of find
    /*/
    // Using STL - Implemantation as defined in <algorithm>
    if (std::find(myList.begin(), myList.end(), 0) != myList.end() ) // !!! std::find instead of find
    //*/
        cout << "Found a 0 in the list." << endl;
}

// }}}

int main()
{
    // Any sequence to fill into list, here the decimal number sequence of Euler's number
    int e[45] = {2,7,1,8,2,8,1,8,2,8,4,5,9,0,4,5,2,3,5,3,6,0,2,8,7,4,7,1,3,5,2,6,6,2,4,9,7,7,5,7,2,4,7,0,9};
    list<int> iList(e,e+45); // Construction of list with 45 elements of sequence of Euler's number.

    foo(iList);

    return 0;
}

/* Input: No input
*/
/* Output:
Found a 0 in the list.

*/