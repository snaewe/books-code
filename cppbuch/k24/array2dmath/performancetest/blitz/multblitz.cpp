/* cppbuch/k24/array2dmath/performancetest/blitz/multblitz.cpp
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
   const size_t LOOPS = 10;

   Array<double, 2> a1(SIZE, SIZE);
   Array<double, 2> a2(SIZE, SIZE);
   Array<double, 2> aerg(SIZE, SIZE);
   a1 = 3.1415926;
   a2 = 3.1415926;
   cout << "Blitz-Array " << SIZE << "x" << SIZE << endl;
   firstIndex i;     // Platzhalter für den ersten Index
   secondIndex j;    // Platzhalter für den zweiten Index
   thirdIndex k;     // Platzhalter für den dritten Index
   clock_t start = clock();
   for(size_t ind = 0; ind < LOOPS; ++ind) {
      // aerg  = a1 * a2; so einfach geht es nicht in Blitz
      aerg = sum(a1(i,k) * a2(k,j), k);
   }
   clock_t ende = clock();
   double dauer =  (double)(ende-start)/CLOCKS_PER_SEC;
   cout <<"Dauer pro Multiplikation und Zweisung aerg = sum(a1(i,k) * a2(k,j), k) :  "
        << dauer/LOOPS  << " Sekunden  (aerg  = a1 * a2 geht nicht)" << endl;
}
