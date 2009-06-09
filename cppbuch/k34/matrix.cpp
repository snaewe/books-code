/* cppbuch/k34/matrix.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include <iostream>
#include"Matrix.h"
using namespace std;

void print(const Matrix& m) {
   for(size_t i = 0; i < m.dim1(); ++i)  {
      for(size_t j = 0; j < m.dim2(); ++j) 
        cout << '\t' << m(i,j);
      cout << endl;
   }
   cout << endl;
}


int main() {
   Matrix m(3,4);
   cout << m.dim1() << 'x' << m.dim2()
        << " Matrix" << endl;
   for(size_t i=0; i< m.dim1(); ++i) 
      for(size_t j = 0; j < m.dim2(); ++j) 
        m[i][j]=double(i)+0.1*j;
   print(m);
   cout << "Multiplikation:  m *= 10.0 :\n";
   m *= 10.0;
   print(m);
   cout << "Zweites Element von Zeile 1 auf 8.88 setzen:\n";
   m.row(1)[2] = 8.88; // same as m[1][2] or m(1,2)
   print(m);
   cout << "Element 0 von Spalte 3 auf 7.7 setzen:\n";
   m.column(3)[0] = 7.7;
   print(m);

}
