/* cppbuch/loesungen/k30/rangvergleich.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef RANGVERGLEICH_H
#define RANGVERGLEICH_H
#include<utility>
#include<string>

class Rangvergleich {
public:
   bool operator()(const std::pair<int, std::string>& p1,
                   const std::pair<int, std::string>& p2) {  // für equal_range
      return p1.first > p2.first;
   }
};

#endif
