/* cppbuch/k23/templateInst/trennIFimpl/instanzen.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"meintypImpl.t"
#include<string>

// explizite Instanziierung
template class MeinTyp<std::string>;
template class MeinTyp<double>;
