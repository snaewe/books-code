/* cppbuch/k7/abstrakt/graphobj.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef GRAPHOBJ_H
#define GRAPHOBJ_H
#include<ort.h>  // enthält #include<iostream>

class GraphObj {                       // Version 2
  public:
    GraphObj(const Ort& einOrt)        // allg. Konstruktor
    : referenzkoordinaten(einOrt) {}

    virtual ~GraphObj() {}             // virtueller Destruktor

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

    // rein virtuelle Methoden
    virtual double flaeche() const = 0;
    virtual void zeichnen()  const = 0;

  private:
    Ort referenzkoordinaten;
};

// Standardimplementierung einer rein virtuellen Methode
inline void GraphObj::zeichnen()  const {
     std::cout << "Zeichnen: ";
}


/* Die Entfernung zwischen 2 GraphObj-Objekten ist hier als
 Entfernung ihrer Bezugspunkte (überladene Funktion)
 definiert.*/

inline double entfernung(const GraphObj& g1, const GraphObj& g2) {
     return entfernung(g1.bezugspunkt(), g2.bezugspunkt());
}
#endif   // GRAPHOBJ_H
