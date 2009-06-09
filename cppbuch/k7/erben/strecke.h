/* cppbuch/k7/erben/strecke.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef STRECKE_H
#define STRECKE_H
#include"graphobj.h"

class Strecke : public GraphObj    {// erben von {\tt GraphObj}
   public:
     // Initialisierung mit Initialisierungsliste
     Strecke(const Ort& ort1, const Ort& ort2)
     : GraphObj(ort1),          // Initialisierung des Subobjekts
     endpunkt(ort2)             // Initialisierung des Attributs
     { }                        // leerer Code-Block

     double laenge() const {
         return entfernung(bezugspunkt(), endpunkt);
     }

   private:
     Ort endpunkt;             // zusätzlich: 2. Punkt der Strecke
                  // (der erste ist {\tt GraphObj::Referenzkoordinaten})
};
#endif // STRECKE_H
