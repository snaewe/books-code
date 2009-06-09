/* cppbuch/k6/meinstring/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"meinstring.h"
#include<iostream>
using namespace std;

int main() {
   MeinString einString("Hallo");
   anzeigen(cout, einString);
   cout << "\nzeichenweise Ausgabe:\n";
   for(size_t i = 0; i < einString.length(); ++i)
      cout << '*' << einString.at(i);
   cout << '*' << endl;
   // Zuweisen
   MeinString zweiterString;
   zweiterString.assign(einString);
   cout << "zugewiesener String: ";
   anzeigen(cout, zweiterString);
   cout << endl;
   // Wird vom Compiler akzeptiert, ist aber falsch:
   zweiterString = einString;
   // weil noch kein eigener Zuweisungsoperator existiert (s. Text)
}
