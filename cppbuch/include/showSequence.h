/* cppbuch/include/showSequence.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef SHOWSEQ_H
#define SHOWSEQ_H
#include<iostream>

template<class Container>
void showSequence(const Container& s, 
                  const char* abschluss = "\n",
                  const char* trennzeichen = " ") {
   typename Container::const_iterator iter = s.begin();
   while(iter != s.end()) {
      std::cout << *iter++ << trennzeichen;
   }
   std::cout << abschluss;
}

#endif

