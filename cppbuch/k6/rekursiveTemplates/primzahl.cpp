/* cppbuch/k6/rekursiveTemplates/primzahl.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
using namespace std;

template<int p, int i> 
struct istPrimzahl { 
   // p ist nur dann prim, wenn p nicht durch i teilbar ist
   // und auch nicht durch alle anderen Teiler zwischen
   // 2 und i. Wenn i==2 ist, wird istPrimzahl<0, 1>::prim
   // gefragt, d.h. Abruch der Rekursion.
   enum {prim = (p%i) && istPrimzahl<(i>2? p:0), i-1>::prim};
};

template<int i> 
struct druckePrimzahlenBis {
   // Der folgende Konstruktoraufruf sorgt dafür, dass auch die
   // kleineren Primzahlen rekursiv ausgegeben werden.
   druckePrimzahlenBis<i-1> a;
   enum { prime = istPrimzahl<i, i-1>::prim};
   druckePrimzahlenBis() {
     if(prime) 
        cout << i << endl;
   }
};

// Rekursionsabbruch durch Spezialisierungen
template<> struct istPrimzahl<0,1> { enum {prim = 1};};
template<> struct druckePrimzahlenBis<2> {  // 
   druckePrimzahlenBis() { cout << 2 << endl; }
};

int main() {
   druckePrimzahlenBis<17> a; 
}
