/* cppbuch/k24/array2dmath/performancetest/boost/addboost.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<ctime>
#include<iostream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
using namespace boost::numeric::ublas;
using namespace std;

int main () {
   const size_t SIZE = 500;
   const size_t LOOPS = 200;
   matrix<double> a1 (SIZE, SIZE);
   matrix<double> a2 (SIZE, SIZE);
   matrix<double> a3 (SIZE, SIZE);
   matrix<double> aerg (SIZE, SIZE);
   for (unsigned i = 0; i < a1.size1 (); ++ i) {
      for (unsigned j = 0; j < a1.size2 (); ++ j) {
            a1 (i, j) = 3.14159;
      }
   }
   a2=a1;
   aerg *= 0;
   cout << "Boost-Matrix " << SIZE << "x" << SIZE << endl;
   clock_t start = clock();
   for(size_t i = 0; i < LOOPS; ++i) {
      aerg = -a1 + 2.0*a2 + a3 ;
   }
   clock_t ende = clock();
   cout << " Boost-Matrix Dauer pro Addition aerg = -a1 + 2.0*a2 + a3 : " 
        <<  (double)(ende-start)/CLOCKS_PER_SEC/LOOPS*1e3 
        << " Millisekunden" << endl;

}
