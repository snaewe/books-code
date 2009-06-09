/* cppbuch/k9/poly/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"unter.h"
using namespace std;

int main() {
    Ober O1(1),
         O2(2);

    cout << "O1 = " << O1.get() << endl;
    cout << "O2 = " << O2.get() << endl;

    Ober O3=O1;
    cout << "\n O3.Kopierkonstruktor(O1):\n";
    cout << "O3 = " << O3.get() << endl;
    cout << "\n O3.operator=(O2):\n";
    O3 = O2;
    cout << "O3 = " << O3.get() << endl;
    cout << " \n Test auf Adressengleichheit\n";
    O3 = O3;

    cout << "\n\nUnter erbt von Ober!\n";
    Unter U1(1,2),
          U2(3,4);

    cout << "U1 = " << U1.get() << endl;
    cout << "U2 = " << U2.get() << endl;

    Unter U3 = U1;
    cout << "\n U3.Kopierkonstruktor(U1):\n";
    cout << "U3 = " << U3.get() << endl;
    cout << "U2 = " << U2.get() << endl;
    cout << "\n U3.operator=(U2):\n";
    U3 = U2;
    cout << "U3 = " << U3.get() << endl;
    cout << "U2 = " << U2.get() << endl;
    cout << "\n Test auf Adressengleichheit\n";
    U3 = U3;

    cout << "\n Polymorphismus:\n";
    Ober & Oref1 = U1;
    Ober & Oref2 = U2;
    cout << "Oref1 = " << Oref1.get() << endl;
    cout << "Oref2 = " << Oref2.get() << endl;
    cout << "polymorphe Zuweisung Oref1 = Oref2:\n";
    Oref1 = Oref2;
    cout << "Oref1 = " << Oref1.get() << endl;
    cout << "Zuweisung mit falschem Typ: Oref1 = O1:"
            "(Programmabbruch provozieren)" << endl;
    Oref1 = O1; // statischer Typ gleich, dynamischer Typ verschieden
}

