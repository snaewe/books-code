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

#include <locale>
#include <iostream>
#include <string>

using namespace ::std;

// p. 281 {{{
template <class String> 
String* compare1toM (locale loc, String one, String* begin, String* end) 
{ 
  const collate<String::value_type>& collateFacet = 
                         use_facet< collate<String::value_type> >(loc); 
  String tmpOne =  
          collateFacet.transform(one.c_str(),one.c_str()+one.length()); 
  for (; begin < end ; begin++) 
  { 
    String tmpMany = collateFacet.transform((*begin).c_str(), 
                                   (*begin).c_str()+(*begin).length()); 
    if (tmpOne == tmpMany) 
      return(begin); 
  } 
  return (end); 
} 
// }}}

int main()
{
	locale loc("German_Germany");

	const int arraySize = 3;
	string strArr[arraySize];
	strArr[0] = "sassen";
	strArr[1] = "sass";
	strArr[2] = "saßen";
	const string * const end = strArr + arraySize;

	string one;
	string * eq;

	one = "saß";
	eq = compare1toM(loc, one, strArr, strArr+arraySize);

	if (end != eq)
		cout << one << " and " << *eq << " are equal." << endl;
	else
		cout << one << " not found" << endl;

    return 0;
}

/* Input: No input
*/
/* Output: Please regard that the DOS - Box representation of ß is ¯
sa¯ and sass are equal.
*/
