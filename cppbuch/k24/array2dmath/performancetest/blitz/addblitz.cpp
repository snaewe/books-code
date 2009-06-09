/* cppbuch/k24/array2dmath/performancetest/blitz/addblitz.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<ctime>
#include <blitz/array.h>
using namespace std;

using namespace blitz;

int main() {
   const size_t SIZE = 500;
   const size_t LOOPS = 1000;

   Array<double, 2> a1(SIZE, SIZE), a2(SIZE, SIZE), a3(SIZE, SIZE);
  Array<double, 2> aerg(SIZE, SIZE);

  a1 = 3.1415926;
  a2 = a1;
  a3 = a1;
  cout << "Blitz-Array " << SIZE << "x" << SIZE << endl;
    clock_t start = clock();
   for(size_t i = 0; i < LOOPS; ++i) {
      aerg = -a1 + 2.0* a2 + a3 ;
   }
   clock_t ende = clock();
   cout << " Blitz-Matrix Dauer pro Addition aerg = -a1 + 2.0*a2 + a3; : " 
        <<  (double)(ende-start)/CLOCKS_PER_SEC/LOOPS*1e3 
        << " Millisekunden" << endl;
}
