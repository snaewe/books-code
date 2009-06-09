/* cppbuch/k9/funktor/sinus.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef SINUS_H
#define SINUS_H
#include<cmath>   //  sin(), Konstante M_PI für pi
// manche Compiler stellen Konstante wie M_PI nicht zur verfügung
#ifndef M_PI
 #define M_PI 3.14159265358979323846
#endif
#include<stdexcept>

class Sinus {
    public:
      enum Modus { bogenmass, grad, neugrad};
      Sinus(Modus m = bogenmass)
      : berechnungsart(m) {
      }

      double operator()(double arg) const {
         double erg;
         switch(berechnungsart) {
         case bogenmass : erg = std::sin(arg);          break;
         case grad      : erg = std::sin(arg/180.0*M_PI); break;
         case neugrad   : erg = std::sin(arg/200.0*M_PI); break;
         default   : ;  // kann hier nicht vorkommen
         }
         return erg;
      }
 private:
      Modus berechnungsart;
};
#endif
