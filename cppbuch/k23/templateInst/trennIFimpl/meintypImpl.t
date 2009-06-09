/* cppbuch/k23/templateInst/trennIFimpl/meintypImpl.t
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"meintyp.t"
#include<vector>

template<typename T>
MeinTyp<T>::MeinTyp(T par) 
: attribut(par) {
}

template<typename T>
T MeinTyp<T>::get() {
   std::vector<T> v; 
   v.push_back(T());  // vector benutzen
   return attribut;
}

