/* cppbuch/k6/meinstringOpt/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"meinstring.h"
#include<iostream>
using namespace std;

int main() {
   MeinString einString("Hallo");
   anzeigen(cout, einString);
   // Zuweisen
   MeinString zweiterString;
   zweiterString.reserve(20);

   zweiterString.assign(einString); // dank reserve() kein new erforderlich
   cout << "\n zugewiesener String: ";
   anzeigen(cout, zweiterString);
   cout << endl;
   cout << "zweiterString.length() : " << zweiterString.length() << endl;
   cout << "zweiterString.capacity() : " << zweiterString.capacity() << endl;
   cout << "nach shrink_to_fit(): " << endl;
   zweiterString.shrink_to_fit();
   cout << "zweiterString.length() : " << zweiterString.length() << endl;
   cout << "zweiterString.capacity() : " << zweiterString.capacity() << endl;
   // Wird vom Compiler akzeptiert, ist aber falsch:
   //zweiterString = einString;
   // weil noch kein eigener Zuweisungsoperator existiert (s. Text)
}
