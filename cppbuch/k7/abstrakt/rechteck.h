/* cppbuch/k7/abstrakt/rechteck.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef RECHTECK_H
#define RECHTECK_H
#include"graphobj.h"

class Rechteck : public GraphObj {  // von {\tt GraphObj} erben
   public:
     Rechteck(const Ort& ort, int h, int b)
     : GraphObj(ort), dieHoehe(h), dieBreite(b)  {}

    // wird von {\tt Quadrat} benötigt
    int hoehe()  const {return dieHoehe;} 
    int breite() const {return dieBreite;}

    // Definition der rein virtuellen Methoden
    virtual double flaeche() const {
        return static_cast<double>(dieHoehe)
             * static_cast<double>(dieBreite);
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
#endif // RECHTECK_H
