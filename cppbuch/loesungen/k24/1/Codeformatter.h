/* cppbuch/loesungen/k24/1/Codeformatter.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef CODEFORMATTER_H
#define CODEFORMATTER_H

#include<fstream>

class Codeformatter {
 public:
   Codeformatter(std::ifstream& i) 
      : is(i), warEOL(true), level(0) {
   }
   void run();
 private:
   void einrueckung();
   void eatblanks();
   void read();
   std::ifstream& is;
   bool warEOL;  // war letztes Zeichen Zeilenende?
   size_t level;
   char c;
   char calt;
};
#endif
