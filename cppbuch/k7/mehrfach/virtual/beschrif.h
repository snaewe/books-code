/* cppbuch/k7/mehrfach/virtual/beschrif.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef BESCHRIF_H
#define BESCHRIF_H
#include"../../abstrakt/graphobj.h"
#include<string>

class BeschriftetesObjekt : virtual public GraphObj  {// erben
  public:
    BeschriftetesObjekt(const Ort& o, const std::string& b)
    : GraphObj(o), beschriftung(b) {
    }

    virtual void zeichnen()  const {
        GraphObj::zeichnen();
        std::cout << "Beschriftung bei ";
        anzeigen(bezugspunkt());
        std::cout <<  beschriftung << std::endl;
    }
  private:
    std::string beschriftung;
};
#endif // BESCHRIF_H
