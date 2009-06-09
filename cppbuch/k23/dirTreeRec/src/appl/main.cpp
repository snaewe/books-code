/* cppbuch/k23/dirTreeRec/src/appl/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
//  Mini-Anwendungsprogramm für die Klasse Rational
#include"../rational/rational.h"
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
   Rational r1(3, 7);
   Rational r2(5, 14);
   druckeTestfall(r1, r2);
   cout <<"Test mit verschiedenen Vorzeichen\n";
   r1.set(3,-7);
   druckeTestfall(r1, r2);

   cout <<"Test mit gemischten Datentypen\n";
   r1.set(2301,77777);
   druckeTestfall(r1, 17);
   druckeTestfall(17, r1);
   cout <<"Testende\n";
}
