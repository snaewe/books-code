/* cppbuch/k11/einf/ohneSTL.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
using namespace std;

// neuer Typname IteratorType für `Zeiger auf const int'
typedef const int* IteratorType;

// Prototyp des Algorithmus
IteratorType find(IteratorType begin, IteratorType end, const int& Value);

int main() {
    const int ANZAHL = 100;
    int einContainer[ANZAHL];          // Container definieren
    IteratorType begin = einContainer; // Zeiger auf den Anfang
    //  Position NACH dem letzten Element
    IteratorType end = einContainer + ANZAHL;

    // Container mit beliebigen Werten füllen (hier: gerade Zahlen)
    for(int i = 0; i < ANZAHL; ++i) {
       einContainer[i] = 2*i;
    }

    int zahl = 0;
    while(zahl != -1) {
       cout << " gesuchte Zahl eingeben (-1 = Ende):";
       cin >> zahl;
       if(zahl != -1) {           // weitermachen?
         IteratorType position = find(begin, end, zahl);
         if (position != end) {
            cout << "gefunden an Position "
                      << (position - begin) << endl;
         }
         else {
            cout << zahl << " nicht gefunden!" << endl;
         }
       }
    }
}

// Implementation
IteratorType find(IteratorType begin, IteratorType end,
              const int& Value) {
    while(begin != end        // Zeigervergleich
          && *begin != Value) // Dereferenzierung und Objektvergleich
         ++begin;             // nächste Stelle
    return begin;
}
