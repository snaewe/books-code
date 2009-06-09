/* cppbuch/loesungen/k3/10/betrag.t
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef BETRAG_T
#define BETRAG_T
#include<iostream>
#include<cstdlib> // für exit()

// Template
template<typename T>
T betrag(T t) { 
   return (t < 0) ? -t : t;
}

// Template-Spezialisierung
template<> char betrag(char c) {
   std::cerr << "Betrag von 'char' ist undefiniert" << std::endl;
   exit(1);
   return c; // damit der Compiler zufrieden ist (wg. exit nicht erreichbar)
}
// Template-Spezialisierung
template<> bool betrag(bool b) {
   std::cerr << "Betrag von 'bool' ist undefiniert" << std::endl;
   exit(1);
   return b;
}
#endif
