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

/*
#include "mendl_184.h"
*/

#ifndef MENDL_H
#define MENDL_H

// p. 184 {{{
template <class charT, class Traits>
basic_mendl<charT, Traits> mendl(unsigned int n, basic_ostream<charT, Traits>&)
{
	return basic_mendl<charT, Traits>(n);
};
// }}}

#endif