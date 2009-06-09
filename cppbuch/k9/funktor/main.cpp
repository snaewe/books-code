/* cppbuch/k9/funktor/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include"sinus.h"

using namespace std;

void sinusAnzeigen(double arg, const Sinus& funktor) {
    cout << funktor(arg) << endl;
}

int main() {
    Sinus sinrad;
    Sinus sinGrad(Sinus::grad);
    Sinus sinNeuGrad(Sinus::neugrad);

    // Aufruf der Objekte wie eine Funktion
    cout << "sin(" << M_PI/4.0 <<" rad) = "            //  pi/4
         << sinrad(M_PI/4.0)   << endl;
    cout << "sin(45 Grad)    = " << sinGrad(45.0)    << endl;
    cout << "sin(50 Neugrad) = " << sinNeuGrad(50.0) << endl;

    // Übergabe eines Funktors an eine Funktion
    sinusAnzeigen(50.0, sinNeuGrad);

    // ...
}
