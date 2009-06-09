/* cppbuch/k7/mehrfach/konflikt/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"bes_r.h"
using namespace std;

int main() {
   Rechteck r(Ort(0,0), 20, 50);

   BeschriftetesRechteck bR(Ort(1,20), 60, 60,
                   string("Mehrfachvererbung"));
   r.zeichnen();
   bR.zeichnen();

   BeschriftetesRechteck *zBR =
                new BeschriftetesRechteck(
                    Ort(100,0), 20, 80,
                    string("dynamisches Rechteck"));

   zBR->zeichnen();
   cout << "Rechteck-Position: ";
   anzeigen(r.bezugspunkt());

   cout << "\n beschriftetes-Rechteck-Position: ";
   //   anzeigen(bR.bezugspunkt());       // Compiler-Fehlermeldung!

   // eindeutig:
   anzeigen(bR.Rechteck::bezugspunkt());

    Rechteck r1(Ort(0,0), 20, 50);
    Rechteck r2(Ort(0,100), 10, 40);
    BeschriftetesRechteck bR2(Ort(1,20), 60, 60,
                   string("Mehrfachvererbung"));

    // Feld mit Basisklassenzeigern, initialisiert mit
    // den Adressen der Objekte, 0 als Endekennung
    GraphObj* GraphObjZeiger[] = {&r1, &r2, 0};   // ok

    // Fehler:
    // {\tt GraphObj* GraphObjZeiger[] = \{\&r1, \&r2, \&bR, 0\};}

    // Zeichnen aller Objekte
    int i = 0;
    while (GraphObjZeiger[i])
           GraphObjZeiger[i++]->zeichnen();
}
