/* cppbuch/k9/new/waechter/ZaehlendesObjekt.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"ZaehlendesObjekt.h"
#include"Waechter.h"

std::set<void*> ZaehlendesObjekt::objekte;
int ZaehlendesObjekt::gesamt = 0;

Waechter w;
