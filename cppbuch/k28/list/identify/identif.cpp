/* cppbuch/k28/list/identify/identif.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"identif.h"
#include<cctype>

// please remove the following macro if your
// compiler supports sentry-objects
// #define SENTRY_NOT_YET_IMPLEMENTED

std::istream& operator>>(std::istream& is, Identifier& N) {
#ifndef SENTRY_NOT_YET_IMPLEMENTED
    std::istream::sentry s(is);
    if(!s) return is;
#endif
    /* The constructor of the sentry-object carries
       out system dependent work. In particular, it checks the input
       stream so that in case of error, we can terminate
       the >> -operator immediately (see Kreft and Langer, 1999). 
        */

    std::string tempIdentifier;
    // find beginning of word
    char c = '\0';
    while(is && !(isalpha(c) || '_' == c))
          is.get(c);
    tempIdentifier += c;

    /* When the beginning is found, all following underscores and
       alphanumeric characters are collected. `White space' or a
       special character terminate the reading process. */

    // collect the rest
    while(is && (isalnum(c) || '_' == c)) {
       is.get(c);
       if(isalnum(c) || '_' == c)
         tempIdentifier += c;
    }

    /* The last character read does not belong to the identifier. The
       iostream} library provides the possibility of returning an
       unused character to the input so that it is available to a
       subsequent program. */
    is.putback(c);   // back into the input stream
    N.theIdentifier = tempIdentifier;
    return is;
}

/* Implementation of the output operator is very easy; the internal
   string variable of an identifier is passed to the output os: */

std::ostream& operator<<(std::ostream& os, const Identifier& N) {
#ifndef SENTRY_NOT_YET_IMPLEMENTED
    std::ostream::sentry s(os);
    if(s) 
#endif
       os << N.toString();
    return os;
}
