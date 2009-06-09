/* cppbuch/k5/qsort.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<cstring>
#include<cstdlib>   // enthält Prototyp von qsort()
using namespace std;

// Definition der Vergleichsfunktion
int icmp(const void *a, const void *b) {
    // Typumwandlung der Zeiger auf {\tt void} in Zeiger auf {\tt int}
    // und anschließende Dereferenzierung (von rechts lesen)
    int ia = *static_cast<const int*>(a);
    int ib = *static_cast<const int*>(b);

    // Vergleich und Ergebnisrückgabe ( > 0, = 0, oder < 0)
    if(ia == ib) return 0;
    return ia > ib ? 1 : -1;
}

int main() {
    int ifeld[] = {100,22,3,44,6,9,2,1,8,9};

    // Die Feldgröße ist die Anzahl der Elemente des Feldes.
    // Feldgröße = sizeof(Feld) / sizeof(ein Element)
    size_t anzahlElemente = sizeof ifeld/ sizeof ifeld[0];

    // Aufruf von qsort():
    qsort(ifeld, anzahlElemente, sizeof(ifeld[0]), icmp);

    // Ausgabe des sortierten Feldes:
    for(size_t i = 0; i < anzahlElemente; ++i)
         cout << " " << ifeld[i];
    cout << endl;
}
