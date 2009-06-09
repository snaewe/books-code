/* cppbuch/k3/per_ref.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
using namespace std;

void addiere_7(int&); //  {\tt int\&} = Referenz auf {\tt int}

int main() {
    int i = 0;
    cout << i << " = alter Wert von i\n";
    addiere_7(i);           // Syntax wie bei Übergabe per Wert
    cout << i << " = neuer Wert von i nach addiere_7\n";
}

void addiere_7(int& x) {
    x += 7;        // Original des Aufrufers wird geändert!
}
