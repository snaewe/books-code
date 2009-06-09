/* cppbuch/loesungen/k9/14_15/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"datum.h"
#include"ungueltigesdatumexception.h"

using namespace std;

int main() {
  Datum einDatum;
  cout << einDatum << " auf 30.2.2010 setzen" << endl;
   try {
      einDatum.set(30, 2, 2010);
   }
   catch(const UngueltigesDatumException& e) {
      cout << e.what() << endl;
   }
}
