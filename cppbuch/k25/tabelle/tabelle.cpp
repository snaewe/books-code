/* cppbuch/k25/tabelle/tabelle.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<cmath>   //  cos(),sin(), Konstante M_PI für pi
// manche Compiler stellen Konstante wie M_PI nicht zur verfügung
#ifndef M_PI
 #define M_PI 3.14159265358979323846
#endif
using namespace std;

int main() {
   cout << "Grad      sin(x)      cos(x)\n";
   cout.setf(ios::showpoint|ios::fixed, ios::floatfield);
   cout.precision(6);

   for (int grad = 0; grad <= 90; grad += 10) {
       // Grad in Bogenmaß umwandeln
       const double rad = static_cast<double>(grad)/180.0*M_PI;
       cout.width(4);  cout << grad;
       cout.width(12); cout << sin(rad);
       cout.width(12); cout << cos(rad) << endl;
   }
}
