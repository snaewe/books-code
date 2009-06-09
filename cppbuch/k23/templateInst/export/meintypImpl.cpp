/* cppbuch/k23/templateInst/export/meintypImpl.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"meintyp.t"

export template<typename T>
MeinTyp<T>::MeinTyp(T par) 
: attribut(par) {
}

export template<typename T>
T MeinTyp<T>::get() {
   return attribut;
}

