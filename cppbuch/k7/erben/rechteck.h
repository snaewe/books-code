/* cppbuch/k7/erben/rechteck.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef RECHTECK_H
#define RECHTECK_H
#include"graphobj.h"

class Rechteck : public GraphObj {   // von {\tt GraphObj} erben
  public:
     Rechteck(const Ort& ort, int h, int b)
     : GraphObj(ort), dieHoehe(h), dieBreite(b)  {}

     double flaeche() const  {
          // {\tt int}-Überlauf vermeiden
         return static_cast<double>(dieHoehe) * dieBreite;
     }

   private:
     int dieHoehe, dieBreite;
};
#endif // RECHTECK_H
