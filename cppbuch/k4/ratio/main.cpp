/* cppbuch/k4/ratio/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
//  Testprogramm für Klasse Rational (Auszug)
#include"rational.h"
#include<iostream>
using namespace std;

// alle 4 Operationen für a und b
void druckeTestfall(const Rational& a, const Rational& b) {
     Rational erg;
     cout << "a = "; a.ausgabe();
     cout << "b = "; b.ausgabe();
     erg = add(a,b);
     cout << "+  : "; erg.ausgabe();
     erg = sub(a,b);
     cout << "-  : "; erg.ausgabe();
     erg = mult(a,b);
     cout << "*  : "; erg.ausgabe();
     erg = div(a,b);
     cout << "/  : "; erg.ausgabe();
     cout << endl;
}

int main() {
     Rational a,b;
     cout << "Test der Eingabe\n";
     a.eingabe();
     b.eingabe();
     druckeTestfall(a,b);

     cout <<"\n Test mit verschiedenen Vorzeichen\n";
     a.set(3,7);    b.set(6,13);
     druckeTestfall(a,b);
     a.set(3,-7);
     druckeTestfall(a,b);
     //...und so weiter

     cout <<"\n Test mit gemischten Datentypen\n";
     a.set(2301,77777);
     druckeTestfall(a,17);
     druckeTestfall(17, a);
     //...und so weiter

     cout <<"\n Test mit Nullwerten\n";
     cout << "Bei einem Nenner = 0 wird ein Fehler provoziert!"
          << endl;
     a.set(0,7);    b.set(6,13);
     druckeTestfall(a,b);
     a.set(3,0);
     druckeTestfall(a,b);
     //...und so weiter
}
