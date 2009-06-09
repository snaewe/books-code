/* cppbuch/k7/abstrakt/quadrat.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef QUADRAT_H
#define QUADRAT_H 
#include"rechteck.h"

class Quadrat : public Rechteck   {// siehe Text
  public:
    Quadrat(const Ort& ort, int seite)
    : Rechteck(ort, seite, seite)  {}

    // Definition der rein virtuellen Methoden
    virtual void zeichnen()  const {
        GraphObj::zeichnen();

        std::cout << "Quadrat (Seitenlaenge = " << hoehe() 
             << ") an der Stelle ";

        anzeigen(bezugspunkt());
        std::cout << std::endl;
    }
    /*  Die Methoden  {\tt bezugspunkt()}, {\tt flaeche()}, {\tt hoehe()},
          {\tt breite()} werden geerbt. */

};
#endif // QUADRAT_H
