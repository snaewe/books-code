/* cppbuch/k1/summe.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>

using namespace std;

int main() {
   int summe;
   int a;
   int b;

    // Lies die Zahlen a und b ein
    cout << " a und b eingeben:";
    cin >> a  >> b;

    /* Berechne die Summe beider Zahlen */
    summe = a+b;

    // Zeige das Ergebnis auf dem Bildschirm an
    cout << "Summe=" << summe;
    return 0;
}

