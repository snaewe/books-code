/* cppbuch/k24/complex/complex.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<complex>               // Header für komplexe Zahlen
#include<cmath>                 // atan() 
using namespace std;

// Beispiele für komplexe Zahlen
// Anstatt {\tt double} sind auch {\tt float} und {\tt long double} möglich.
int main() {
   complex<double> c1;            // komplexe Zahl 0.0 + 0.0{\it i}
   complex<double> c2(1.2, 3.4);  // (1.2 + 3.4{\it i}) erzeugen
   cout << c2 << endl;            // Standard-Ausgabeformat: (1.2,3.4)

   c1 += c2 + c1;                 // beispielhafte Rechenoperationen
   c1 = c2 * 5.0;

   double re = c1.real();         // Realteil ermitteln
   cout << re << endl;            // und ausgeben
   cout << c1.imag() << endl;     // Imaginärteil direkt ausgeben

   // Beispiele mit Hilfsfunktionen

   complex<double> c3(1.0,2.0);   // (1.0 + 2.0{\it i}) erzeugen
   c1 = conj(c3);                 // konjugiert komplex: (1.0 - 2.0{\it i})

   // Umrechnung aus Polarkoordinaten
   const double PI = 4.0 * atan(1.0); // $\pi$ berechnen
   double betrag = 100.0,
         phase  = PI/4.0;             // $\pi/4 = 45^\circ$
   c1 = polar(betrag, phase);   

   // Umrechnung in Polarkoordinaten
   double rho   = abs(c1);            // Betrag $\rho$
   double theta = arg(c1);            // Winkel $\theta$

   double nrm = norm(c1);             // Betragsquadrat

   cout << "Betrag  = " << betrag << endl;
   cout << "rho     = " << rho    << endl;
   cout << "Norm    = " << nrm    << endl;
   cout << "Phase   = " << phase  << endl;
   cout << "theta   = " << theta
        << " = " << theta/PI*180. << " Grad" << endl;

   cout << "Komplexe Zahl eingeben. Erlaubte Formate (Beispiel):"
           "\n (1.78, -98.2)\n (1.78)\n 1.78\n:";
   cin >> c1;
   cout << "komplexe Zahl = " << c1 << endl;      
}
