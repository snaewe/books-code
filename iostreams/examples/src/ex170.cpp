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

// This example was run with Microsoft Visual C++.NET 7.0 beta version. There seems to be a bug
// so that the entered date 09/10/99 changed to 10/09/99. This might not occur in other environments
#include <iostream>
#include <ctime>
#include <sstream>
#include <locale>

using namespace ::std;

#include "date_170.h"

int main()
{
    date d;
    cin >> d;
    cout << d;

    return 0;
}

/* Input:
09/10/99
*/
/* Output:
10/09/99
*/