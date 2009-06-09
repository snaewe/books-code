/* cppbuch/k23/templateInst/inklusion/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include"func01.h"
#include"func02.h"

int main() {
std::cout << "Aufruf von func01(): "; 
func01();
std::cout << "Aufruf von func02(): "; 
func02();
}
