/* cppbuch/k3/kleiner.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
using namespace std;

template<typename T>
bool kleiner(const T& a, const T& b)  { // Vergleich
    return (a<b);
}

bool kleiner1(int a, int b)  { // gewöhnliche Funktion
    return (a<b);
}


int main () {
  cout <<  (kleiner(3, 6) ? 3 : 6) << endl; // Template, Ausgabe 3
  //cout <<  (kleiner(3.4, 6) ? 3 : 6) << endl; no match!

 // gew. Funktion (Compiler-Warnung wg. double-int-Wandlung):
  cout <<  (kleiner1(3.1, 3.3) ? 3.1 : 3.3) << endl; // Ausgabe 3.3
      // Falsches Ergebnis wg. Genauigkeitsverlust bei Wandlung
} // Ende von {\tt main()}
