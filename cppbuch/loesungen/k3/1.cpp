/* cppbuch/loesungen/k3/1.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<cmath>  // wegen pow(), s.u.
using namespace std;

double power(double x, int y);

int main() {
   cout << "x^y berechnen. Zahlen x und y eingeben (y ganzzahlig):";
   double x;
   int y;
   cin >> x >> y;
   cout << "x^y  = " << power(x, y) << endl;
   cout << "pow(x,y)  = " << pow(x, y) << endl; // aus cmath
}

// Die Funktion power() entspricht der Funktion  pow()
//  der C++-Bibliothek ( <cmath>}.

double power(double x, int y) {
   double ergebnis = 1;
   bool negativ = false;
   if(y < 0) {
      y = -y;
      negativ = true;
   }
   for(int i=0; i < y; ++i) {
      ergebnis *= x;
   }
   if(negativ) {
      ergebnis = 1.0/ergebnis;
   }
   return ergebnis;
}
