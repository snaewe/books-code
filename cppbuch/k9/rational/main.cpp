/* cppbuch/k9/rational/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
// Testprogramm für Klasse Rational mit Operatoren
// nur Additions und Ausgabeoperator
#include"ratioop.h"
#include<iostream>
using namespace std;

// nur Addition a und b, Rest fehlt
void druckeTestfall(Rational a, Rational b) {
     cout << "a = "; cout << a << endl;
     cout << "b = "; cout << b << endl;
     cout << "+  : "; cout << (a+b) << endl;
     if (a == b)  // boolscher Operator
         cout << a << " == " << b << endl;
     else
         cout << a << " != " << b << endl;
     cout << "a += b = ";
     a += b;
     cout << a << endl;
}

int main() {
     Rational a,b;
     cout << "Test des Eingabeoperators\n";
     cout << "a:\n"; cin >> a;
     cout << "b:\n"; cin >> b;
     druckeTestfall(a,b);

     cout <<"\n Test mit verschiedenen Vorzeichen\n";
     a.set(3,7);    b.set(6,13);   druckeTestfall(a,b);
     a.set(3,-7);                  druckeTestfall(a,b);
     a.set(-3,-7);                 druckeTestfall(a,b);
     a.set(-3,-17); b.set(-6,-13); druckeTestfall(a,b);

     cout <<"\n Test mit Nullwerten\n";
     // Nenner = 0 nach Test auskommentieren
     a.set(0,7);    b.set(6,13);   druckeTestfall(a,b);
     a.set(3,7);    b.set(0,3);    druckeTestfall(a,b);

     cout <<"\n Test mit gemischten Datentypen\n";
     a.set(2301,77777);
     druckeTestfall(a,17);         druckeTestfall(17, a);

     cout <<"\n Test mit gemischten Datentypen, Zahlen < 0\n";
     druckeTestfall(a,-17);        druckeTestfall(-17, a);
     cin.get();
}
