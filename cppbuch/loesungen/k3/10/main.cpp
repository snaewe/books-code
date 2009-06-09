/* cppbuch/loesungen/k3/10/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include"betrag.t"
using namespace std;

int main() {
   int i = -1;
   cout << "Der Betrag von " << i
        << " ist " << betrag(i) << endl;
   double d = -2.345;
   cout << "Der Betrag von " << d
        << " ist " << betrag(d) << endl;
   // Fehlermeldung provozieren
   bool b = true;
   cout << "Der Betrag von " << b
        << " ist " << betrag(b) << endl;
}
