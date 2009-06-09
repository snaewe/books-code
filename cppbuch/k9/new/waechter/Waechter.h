/* cppbuch/k9/new/waechter/Waechter.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef WAECHTER_H
#define WAECHTER_H
#include"ZaehlendesObjekt.h"

class Waechter {
public:
   ~Waechter() {
      if(ZaehlendesObjekt::objekte.size() > 0) {
         std::cerr << "Es fehlen " << ZaehlendesObjekt::objekte.size()
                   << " delete-Anweisungen!" << std::endl;
      }
   }
};

#endif
