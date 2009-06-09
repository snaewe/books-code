/* cppbuch/k27/binaryfunc/addierer.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include <functional>
#include <iostream>


int main() {
   std::plus<double> addierer;
   double d1 = 3.1415926;
   double d2 = 2.718;
   std::cout << d1 << " + " << d2 << " = "
        << addierer(d1, d2) << std::endl;
}
