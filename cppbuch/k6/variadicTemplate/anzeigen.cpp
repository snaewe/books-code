/* cppbuch/k6/variadicTemplate/anzeigen.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
// nach [GrJä]

void anzeigen() { 
   std::cout << std::endl;
}
 
template<typename T, typename... Rest>
void anzeigen(const T& obj, const Rest&... rest) {
   std::cout << obj << " ";
   anzeigen(rest...);
}

int main() {
   anzeigen(1);
   anzeigen(2, "Hallo");
   anzeigen("Text", 7.978353, 3);
}

