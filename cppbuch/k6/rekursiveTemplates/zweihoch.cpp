/* cppbuch/k6/rekursiveTemplates/zweihoch.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>

template<int n>
struct Zweihoch {
  enum { wert = 2*Zweihoch<n-1>::wert};
};

template<> struct Zweihoch<0> {
   enum { wert = 1};
};

int main() {
    std::cout << Zweihoch<11>::wert << std::endl;
}
