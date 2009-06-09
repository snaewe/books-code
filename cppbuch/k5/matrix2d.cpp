/* cppbuch/k5/matrix2d.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
using namespace std;

int main() {
   const size_t DIM1 = 2;
   const size_t DIM2 = 3;
   int matrix [DIM1] [DIM2] = { {1,2,3}, 
                                {4,5,6} };

   for (size_t i = 0; i < DIM1; ++i) {
      for (size_t j = 0; j < DIM2; ++j) {
         cout << matrix[i][j] << ' ';
      }
      cout << endl;
   }
}
