/* cppbuch/k23/templateInst/trennIFimpl/func01.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"func01.h"
#include"meintyp.t"
#include<iostream>
#include<string>
void func01() {
  MeinTyp<std::string> mt("func01");
   std::cout << mt.get() << std::endl;
}
