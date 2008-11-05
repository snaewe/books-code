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

using namespace ::std;

// p. 328 {{{
template <class charT>
class boolnames : public numpunct_byname<charT>
{
// }}}
// p. 329 {{{
    protected:
        charT const * const true_;
        charT const * const false_;
        basic_string<charT> do_truename() const {
            return true_;
        }
        basic_string<charT> do_falsename() const {
            return false_;
        }
        ~boolnames() { }
    public:
        explicit boolnames(const char * locnam, const charT* t,
                           const charT* f, size_t refs = 0)
                           : numpunct_byname<charT>(locnam, refs), true_(t), false_(f) {}
};

int main(int argc, char ** argv)
{
    locale loc(locale("US"), new boolnames<char>("US","yes","no"));
    cout.imbue(loc);

    bool any_args = (argc > 1);
    cout << "Any arguments? " << boolalpha << any_args << endl;
	// ...
	// {{{
	// To ensure that both do_truename and do_falsename are invoked:
	cout << "otherwise the answer would be " << !any_args << endl;
    return 0;
	// }}}
}
// }}}

/*
Start program with any argument
*/
/* Input:
*/
/* Output:
Any arguments? yes
otherwise the answer would be no
*/