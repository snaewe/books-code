/* cppbuch/k11/einf/mitVector.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<vector>
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

// neuer Typname zur Verbesserung der Lesbarkeit
typedef vector<int>::const_iterator IteratorType;

int main() {
   const int ANZAHL = 100;
   vector<int> einContainer(ANZAHL);  // Container definieren

   // Container mit beliebigen Werten füllen (hier: gerade Zahlen)
   for(int i = 0; i < ANZAHL; ++i) {
      einContainer[i] = 2*i;
   }

   int zahl = 0;
   while(zahl != -1) {
      cout << " gesuchte Zahl eingeben (-1 = Ende):";
      cin >> zahl;
      if(zahl != -1) {           // weitermachen?
         // globales find() von oben benutzen
         IteratorType position =
            ::find(einContainer.begin(), // Container-Methoden
                   einContainer.end(), zahl);

         if (position != einContainer.end()) {
            cout << "gefunden an Position "
                 << (position - einContainer.begin()) << endl;
         }
         else {
            cout << zahl << " nicht gefunden!" << endl;
         }
      }
   }
}
