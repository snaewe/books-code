/* cppbuch/loesungen/k6/1/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"meinstring.h"
#include<iostream>
using namespace std;

int main() {
   MeinString a("Guten");
   MeinString b(" Tag");
   // Test von insert()
   for(size_t i = 0; i < b.length()+2; ++i) {
      MeinString c(b);
      anzeigen(cout, c);
      cout << " wird: ";
      c.insert(i, a);
      anzeigen(cout, c);
      cout << endl;
   }
}
