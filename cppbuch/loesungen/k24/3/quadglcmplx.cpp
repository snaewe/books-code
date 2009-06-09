/* cppbuch/loesungen/k24/3/quadglcmplx.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
// Beispiel quadratische Gleichung {\tt x*x+p*x+q = 0}
// {\tt x1 = -p/2 + sqrt(p*p/4-q), x2 = -p/2 - sqrt(p*p/4-q)}
#include <iostream>
#include <cmath>
#include<complex>  
using namespace std;

int main() {
   cout << "Quadratische Gleichung x*x+p*x+q = 0\n";
   cout << "Koeffizienten p, q eingeben:";
   double p, q;
   cin >> p >> q;
   double Diskriminante = p*p/4.0 - q;

   cout << "Lösung :\n";
   if (Diskriminante >= 0.0) {
      double x1 = -p/2.0 + sqrt(Diskriminante);
      double x2 = -p/2.0 - sqrt(Diskriminante);
      cout << "x1= " << x1 << "   x2= " << x2 <<endl;
   }
   else {
      complex<double> ergebnis(-p/2, sqrt(-Diskriminante));
      cout << "x1 = " << ergebnis << endl;
      cout << "x2 = " << conj(ergebnis) << endl;
   }
}
