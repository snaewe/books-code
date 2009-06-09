/* cppbuch/k11/einf/ohneSTLmitTemplate.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
using namespace std;

// Prototyp des Algorithmus ersetzt durch Template
template<class Iterator, typename T>
Iterator find(Iterator begin, Iterator end,
                  const T& Value) {
    while(begin != end        // iterator comparison
          && *begin != Value) // dereferencing and object comparison
         ++begin;             // next position
    return begin;
}

// neuer Typname IteratorType für `Zeiger auf const int'
typedef const int* IteratorType;


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
