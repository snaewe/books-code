/* cppbuch/k3/fakulta2.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
using namespace std;

// Funktionsprototyp (Deklaration)
unsigned long fakultaet(int);

int main() {
   int n;
   do {
      cout << "Fakultät berechnen. Zahl >= 0? :";
      cin >> n;
   } while(n < 0);

   cout << "Das Ergebnis ist "
        << fakultaet(n) << endl;              // Aufruf

   // alternativ mit Zwischenablage des Ergebnisses:
   unsigned long erg = fakultaet(n);
   cout << "Das Ergebnis ist " << erg << endl;
}

// Funktionsimplementation (Definition)
unsigned long fakultaet(int zahl) {
   unsigned long fak = 1;
   for(int i = 2; i <= zahl; ++i)
      fak *= i;
   return fak;
}
