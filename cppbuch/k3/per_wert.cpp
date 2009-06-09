/* cppbuch/k3/per_wert.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
using namespace std;

int addiere_5(int);      // Deklaration (Funktionsprototyp)

int main() {
    int erg, i = 0;
    cout << i << " = Wert von i\n";
    erg = addiere_5(i);
    cout << erg << " = Ergebnis von addiere_5\n";
    cout << i << " = i unverändert!\n";
}

int addiere_5(int x) {   // Definition
     x += 5;
     return x;
}
