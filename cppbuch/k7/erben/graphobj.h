/* cppbuch/k7/erben/graphobj.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef GRAPHOBJ_H
#define GRAPHOBJ_H
#include"ort.h"

class GraphObj {                       // Version 1
  public:
    GraphObj(const Ort& einOrt)        // allg. Konstruktor
    : referenzkoordinaten(einOrt) {}

       virtual ~GraphObj() {} // siehe Abschnitt "Virtueller Destruktor"

    // Bezugspunkt ermitteln
    const Ort& bezugspunkt() const { return referenzkoordinaten;}

    // alten Bezugspunkt ermitteln und gleichzeitig neuen wählen
    Ort bezugspunkt(const Ort& nO) {
        Ort temp = referenzkoordinaten;
        referenzkoordinaten = nO;
        return temp;
    }

    // Koordinatenabfrage
    int getX() const { return referenzkoordinaten.getX(); }
    int getY() const { return referenzkoordinaten.getY(); }

    // Standardimplementation:
    double flaeche() const {return 0.0;}
  private:
    Ort referenzkoordinaten;
};

/* Die Entfernung zwischen 2 GraphObj-Objekten ist hier als
 Entfernung ihrer Bezugspunkte (überladene Funktion)
 definiert.*/
inline double entfernung(const GraphObj& g1, const GraphObj& g2) {
     return entfernung(g1.bezugspunkt(), g2.bezugspunkt());
}
#endif   // GRAPHOBJ_H
