/* cppbuch/k24/array2dmath/performancetest/array2d/mult.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#if  __GNUC__*10+__GNUC_MINOR__ < 44
#error "Die Compilation dieses Programms setzt mindestens GNU C++ 4.4 voraus!"
#else

#include<iostream>
#include<ctime>
#include"../../array2d.h"
using namespace std;

int main() {
   const size_t SIZE = 500;
   const size_t LOOPS = 10;
   Array2d<double> a1(SIZE, SIZE, 3.1415926);
   Array2d<double> a2(a1);
   Array2d<double> aerg(SIZE, SIZE);
   cout << "Array2d " << SIZE << "x" << SIZE << endl;
   clock_t start = clock();
   for(size_t i = 0; i < LOOPS; ++i) {
      aerg = a1*a2;
   }
   clock_t ende = clock();
   double dauer =  (double)(ende-start)/CLOCKS_PER_SEC;
   cout <<"Dauer pro Multiplikation und Zweisung aerg = a1*a2 :  "
   << dauer/LOOPS  << " Sekunden" << endl;
}
#endif
