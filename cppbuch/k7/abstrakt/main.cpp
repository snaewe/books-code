/* cppbuch/k7/abstrakt/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
// Hauptprogramm

#include"strecke.h"
#include"quadrat.h"  // schliesst {\em rechteck.h} ein


int main() {
    // {\tt GraphObj g;  //} Fehler!
                   // Instanzen abstrakter Klassen gibt es nicht.

    Rechteck r(Ort(0,0), 20, 50);
    Strecke  s(Ort(1,20), Ort(200,0));
    Quadrat  q(Ort(122, 99), 88);

    // Feld mit Basisklassenzeigern, initialisiert mit
    // den Adressen der Objekte und 0 als Endekennung
    GraphObj* graphObjZeiger[] = {&r, &s, &q, 0};

    // Ausgabe der Fläche aller Objekte
    int i = 0;
    while (graphObjZeiger[i])
        std::cout << "Fläche = "
                  << graphObjZeiger[i++]->flaeche() << std::endl;

    // Zeichnen aller Objekte
    i = 0;
    while (graphObjZeiger[i])
           graphObjZeiger[i++]->zeichnen();

    std::cout << "Auch Referenzen sind polymorph:\n";
    GraphObj &r_ref = r,   // Der statische Typ ist derselbe,
             &s_ref = s,
             &q_ref = q;
    r_ref.zeichnen();      // der dynamische nicht.
    s_ref.zeichnen();
    q_ref.zeichnen();
}
