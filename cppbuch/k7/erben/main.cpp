/* cppbuch/k7/erben/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"strecke.h"
#include"rechteck.h"
using namespace std;

int main() {
    // Definition zweier graphischer Objekte
   Ort nullpunkt;
    GraphObj g0(nullpunkt);
    Ort einOrt(10, 20);
    GraphObj g1(einOrt);

    // Ausgabe beider Bezugspunkte auf verschiedene Art
    cout << "g0.getX() = " <<  g0.getX() << endl;
    cout << "g0.getY() = " <<  g0.getY() << endl;
    Ort ort = g1.bezugspunkt();

    cout << "ort.getX() = " <<  ort.getX() << endl;
    cout << "ort.getY() = " <<  ort.getY() << endl;

    // Ausgabe der Entfernung
    cout << "Entfernung = " << entfernung(g0, g1) << endl;

    cout << "neuer Bezugspunkt für g0:" << endl;
    g0.bezugspunkt(ort);        // Rückgabewert wird hier ignoriert
    cout << "g0.bezugspunkt() = ";
    anzeigen(g0.bezugspunkt());
    cout << "\n Entfernung = " << entfernung(g0, g1) << endl;

    Ort anf;
    Strecke s1(anf, ort);

    cout << "Strecke von ";
    anzeigen(anf);
    cout << " bis ";
    anzeigen(ort);

    cout << "\n Fläche der Strecke s1 = "
         << s1.flaeche()               // geerbte Methode
         << endl;

    cout << "Länge der Strecke s1 = "
         << s1.laenge()                // zusätzliche Methode
         << endl;

    einOrt = Ort(20, 30);              // Neuzuweisung
    Ort ort2(100, 50);
    Strecke s2(einOrt, ort2);

    cout << "= Entfernung der Bezugspunkte: "
         << entfernung(s1.bezugspunkt(), s2.bezugspunkt())
         << endl;

    cout << "Entfernung der Strecken s1, s2 = "
         << entfernung(s1, s2) << endl;
    // ...


    Rechteck rechteck(Ort(0,0), 20, 50);
    cout << "rechteck.flaeche = "
         <<  rechteck.flaeche() << endl;      // 1000

    cout << rechteck.GraphObj::flaeche();  // null!
}
