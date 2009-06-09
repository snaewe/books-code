/* cppbuch/k24/array2dmath/performancetest/array2d/add.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#if  __GNUC__*10+__GNUC_MINOR__ < 44
#error "Die Compilation dieses Programms setzt mindestens GNU C++ 4.4 voraus!"
#else

#include<iostream>
#include<ctime>
#include<valarray>
#include"../../array2d.h"
using namespace std;

int main() {
   const size_t SIZE = 500;
   const size_t LOOPS = 1000;
   // Array2d
   Array2d<double> a1(SIZE, SIZE, 3.14159);
   Array2d<double> a2(SIZE, SIZE, 2.7182);
   Array2d<double> a3(SIZE, SIZE, 1.11111);
   Array2d<double> aerg(SIZE, SIZE, 0.0);
   cout << "Array " << SIZE << "x" << SIZE << endl;
   clock_t start = clock();
   for(size_t i = 0; i < LOOPS; ++i) {
      aerg = -a1 + 2.0 *a2 + a3;
   }
   clock_t ende = clock();
   cout << " Array2d Dauer pro Addition aerg = -a1 + 2.0 *a2 + a3; : " 
        <<  (double)(ende-start)/CLOCKS_PER_SEC/LOOPS*1e3 
        << " Millisekunden" << endl;

   // valarray
   valarray<double> va1(3.14159, SIZE*SIZE);
   valarray<double> va2(2.7182, SIZE*SIZE);
   valarray<double> va3(1.11111, SIZE*SIZE);
   valarray<double> verg(0.0, SIZE*SIZE);
   start = clock();
   for(size_t i = 0; i < LOOPS; ++i) {
      verg = -va1 + 2.0 *va2 + va3;
   }
   ende = clock();
   cout << " valarray Dauer pro Addition  verg = -va1 + 2.0 *va2 + va3 : " 
        <<  (double)(ende-start)/CLOCKS_PER_SEC/LOOPS*1e3 
        << " Millisekunden" << endl; 
}
#endif
