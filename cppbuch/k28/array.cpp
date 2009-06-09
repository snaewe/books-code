/* cppbuch/k28/array.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#if  __GNUC__*10+__GNUC_MINOR__ < 44 
#include<tr1/array>
using namespace std::tr1;
#else
#include<array>
#endif
using namespace std;

int main() {
   const size_t ANZAHL = 3;
   array<int, ANZAHL> tabelle  = {{ 9, -10, 5 }};

   // Benutzung mit Iterator
   for(array<int, ANZAHL>::const_iterator i = tabelle.begin(); 
       i != tabelle.end(); ++i) {
      cout << *i << endl;
   }
   // Benutzung wie Vektor
   for(size_t  i = 0; i < tabelle.size(); ++i) {
      cout << tabelle[i] << endl;
   }
   // Benutzung wie Tupel
   cout << get<0>(tabelle) << endl;
   cout << get<1>(tabelle) << endl;
   cout << get<2>(tabelle) << endl;
}
