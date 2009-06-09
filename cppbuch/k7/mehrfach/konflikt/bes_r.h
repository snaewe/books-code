/* cppbuch/k7/mehrfach/konflikt/bes_r.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef BES_R_H
#define BES_R_H
#include"beschrif.h"
#include"rechteck.h"

// Mehrfachvererbung
class BeschriftetesRechteck
   : public BeschriftetesObjekt, public Rechteck {
  public:
    BeschriftetesRechteck(const Ort& o, int h, int b,
                          const std::string& beschr)
    : BeschriftetesObjekt(o, beschr),
      Rechteck(o, h, b)
    {}

    // Definition der rein virtuellen Methoden
    virtual double flaeche() const {
        // Definition ist notwendig, damit die Klasse
        // nicht abstrakt ist (durch Vererbung über
        // {\tt BeschriftetesObjekt} und {\tt GraphObj})
        return Rechteck::flaeche();
    }

    virtual void zeichnen()  const {
        Rechteck::zeichnen();
        BeschriftetesObjekt::zeichnen();
    }
};
#endif // BES_R_H
