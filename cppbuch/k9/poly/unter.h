/* cppbuch/k9/poly/unter.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef UNTER_H
#define UNTER_H
#include"ober.h"

class Unter : public Ober {
  public:
    Unter(int io, int iu)
    : Ober(io), iU(iu) {
    }
    virtual int get() const {
       return (10*Ober::get() + iU);
    }

    virtual Unter& assign(const Ober& rs) {
       std::cout << "Unter::this = " << (unsigned)this
                 << "        &rs = " << (unsigned)(&rs) <<std:: endl;
       if(this != &rs) {
          Ober::assign(rs);        // Oberklassensubobjekt
         /* Die rechte Seite rs wird hier zur Laufzeit in eine
          Referenz rs mit dem erforderlichen Typ gewandelt.  rs
         gehört zur Klasse Unter, so dass der Compiler ab hier 
         keine Typkonflikte mehr hat.*/
          const Unter& U = dynamic_cast<const Unter&>(rs);
          lokaleZuweisung(U);      // nur lokale Daten
       }
       return *this;
    }
    // um Generierung des impliziten Operators zu vermeiden,
    // muss Unter& operator=(const Unter& rs) existieren.
    Unter& operator=(const Unter& rs) { return assign(rs); }

  protected:
    void lokaleZuweisung(const Unter& rs) {
       iU = rs.iU;
    }
  private:
    int iU;   // Daten speziell für Unter
};
#endif
