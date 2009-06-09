/* cppbuch/loesungen/k4/4/automat.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"automat.h"
#include<iostream>
using namespace std;

GetraenkeAutomat::GetraenkeAutomat( int anzahl,
                                    int dosenpreis)
: anzahlDosen(anzahl), preisProDose(dosenpreis),
  einnahmen(0), eingeworfeneMuenzen(0), rueckgeld(0),
  doseInAusgabe(false), gesperrt(anzahl <= 0)
{}

void GetraenkeAutomat::geldPruefenUndDoseHerausgeben() {
     if (gesperrt) {
          cout << " Automat leer/gesperrt!" << endl;
          rueckgeld = eingeworfeneMuenzen;
     }
     else
         if (eingeworfeneMuenzen < preisProDose) {
              cout << " Geld reicht nicht!" << endl;
              rueckgeld = eingeworfeneMuenzen;
         }
         else {
             einnahmen += preisProDose;
             rueckgeld = eingeworfeneMuenzen - preisProDose;
             cout << " Dose fällt in Ausgabe! (rumpel)"
                  << endl;
             doseInAusgabe = true;
             if (--anzahlDosen == 0)
                 gesperrt = true;
         }
     eingeworfeneMuenzen = 0;  // weitere Nutzung verhindern
}

void GetraenkeAutomat::muenzenAkzeptieren(int m) {
     eingeworfeneMuenzen = m;
     cout<< " " << m << " Euro eingeworfen" << endl;
}

int GetraenkeAutomat::geldRueckGabe() {
    int temp = rueckgeld;
    rueckgeld = 0;
    cout << " Geldrückgabe: "
         << temp << " Euro" << endl;

    return temp;
}// Ende von automat.cpp
