/* cppbuch/loesungen/k5/4.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
/* Da eine echte dreidimensionale Ausgabe in der Ebene nicht möglich ist,
  werden  n  (DIM2 x DIM3)-Matrizen ausgegeben.
*/
#include<iostream>
using namespace std;

template<typename Feldtyp>
void Tabellenausgabe3D(Feldtyp T, size_t n) { 
   const size_t DIM2 = sizeof T[0] /sizeof T[0][0];
   const size_t DIM3 = sizeof T[0][0] /sizeof T[0][0][0];
   for(size_t i = 0; i < n; ++i) {
      for(size_t j = 0; j < DIM2; ++j) {
         for(size_t k = 0; k < DIM3; ++k)
            cout << T[i][j][k] << ' ';
         cout << endl;
      }
      cout << endl;
   }
   cout << endl;
}

int main() {
   const int N = 2, M = 3, Q = 4;
   int mat3D[N][M][Q];  // 3D-Matrix
   // Mit Werten füllen
   int m = 0;
   for(int i = 0; i < N; ++i) {
      for(int j = 0; j < M; ++j) {
         for(int k = 0; k < Q; ++k)
            mat3D[i][j][k] = ++m;
      }
   }
   Tabellenausgabe3D(mat3D, N);
}
