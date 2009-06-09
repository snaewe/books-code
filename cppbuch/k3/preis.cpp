/* cppbuch/k3/preis.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<string>
using namespace std;

// Funktionsprototyp        2. Parameter mit Vorgabewert:
void preisAnzeige(double preis,
                  const string& waehrung="Deutsche Mark");

// Hauptprogramm
int main() {
     // zwei Aufrufe mit unterschiedlicher Parameterzahl :
     preisAnzeige(12.35);   // Default-Parameter wird eingesetzt
     preisAnzeige(99.99,"US-Dollar");
}

// Funktionsimplementation
void preisAnzeige(double preis, const string& waehrung) {
      cout << preis << ' ' << waehrung << endl;
}
