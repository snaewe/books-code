/* cppbuch/loesungen/k30/gleicherrang.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef GLEICHERRANG_H
#define GLEICHERRANG_H
#include<utility>
#include<string>

class GleicherRang {
 public:
   GleicherRang(int r) : rang(r) {
   }
   bool operator()(const std::pair<int, std::string>& p) {  // für count_if
      return p.first == rang;
   }
 private:
   int rang;
};

#endif
