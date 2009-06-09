/* cppbuch/k7/mehrfach/konflikt/rechteck.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef RECHTECK_H
#define RECHTECK_H 
#include"../../abstrakt/graphobj.h"

class Rechteck : public GraphObj   // von {\tt GraphObj} erben
{  public:
     Rechteck(const Ort& p1, int h, int b)
     : GraphObj(p1), dieHoehe(h), dieBreite(b)  {}

    // wird von {\tt Quadrat} benötigt
    int hoehe()  const {return dieHoehe;} 
    int breite() const {return dieBreite;}

    // Definition der rein virtuellen Methoden
    virtual double flaeche() const {
        // int-Overflow vermeiden
        return double(dieHoehe) * dieBreite;
    }

    virtual void zeichnen()  const {
        GraphObj::zeichnen();
        std::cout << "Rechteck (h x b = "
             << dieHoehe << " x "
             << dieBreite
             << ") an der Stelle ";
        anzeigen(bezugspunkt());
        std::cout << std::endl;
    }
   private:
     int dieHoehe, dieBreite;
};
#endif // rechteck_h
