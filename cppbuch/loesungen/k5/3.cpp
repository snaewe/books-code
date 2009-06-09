/* cppbuch/loesungen/k5/3.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
using namespace std;

template<typename Feldtyp>
void tabellenausgabe2D(Feldtyp Tabelle, size_t n) { 
  const size_t SPALTEN = sizeof Tabelle[0] /sizeof Tabelle[0][0];
  for(size_t i = 0; i < n;++i) {
    for(size_t j = 0; j < SPALTEN;++j)
      cout << Tabelle[i][j] << ' ';
    cout << endl;
  }
  cout << endl;
}

int main() {
   /* Es muss m = p, r = n und s = q gelten, damit die
      Matrizenmultiplikation definiert ist. Daher benötigt man nur
      noch drei Konstanten. 
    */
    // Initialisierung (Beispiel)
    const int N = 2, M = 3, Q = 4;
    int a[N][M] = {{1,2,3}, {4,5,6}};
    int b[M][Q] = {{1,2,3,0},{4,1,1,5},{1,7,1,4}};
    int c[N][Q];

    // Multiplikation
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < Q; ++j) {
            c[i][j] = 0;
            for(int k = 0; k < M; ++k)
                 c[i][j] += a[i][k] * b[k][j];
        }
    }
    // Ergebnis ausgeben oder weiterrechnen
    tabellenausgabe2D(a, N);
    cout << "multipliziert mit " << endl;
    tabellenausgabe2D(b, M);
    cout << "ergibt" << endl;
    tabellenausgabe2D(c, N);
    // ...
}
