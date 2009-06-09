/* cppbuch/k6/variadicTemplate/paramzaehlen.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
// nach [GrJ]
// Template-Deklaration
template<typename... Args> struct Anzahl;

// partielle Spezialisierung (Rekursion)
template<typename Head, typename... Tail>
struct Anzahl<Head, Tail...> { 
   static const int wert = 1 + Anzahl<Tail...>::wert;
};

// partielle Spezialisierung (Rekursionsabbruch)
template<>
struct Anzahl<> {
  static const int wert = 0;
};

int main() {
   std::cout << "Parameteranzahl von Anzahl<char*, int, double>: " 
             << Anzahl<char*, int, double>::wert << std::endl;
}
