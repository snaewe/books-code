/* cppbuch/k23/templateInst/extern/func02.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"func02.h"
#include"meintyp.t"
#include<iostream>
extern template class MeinTyp<double>;
void func02() {
  MeinTyp<double> mt(3.1415926);
   std::cout << mt.get() << std::endl;
}
