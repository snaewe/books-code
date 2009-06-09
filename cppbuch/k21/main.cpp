/* cppbuch/k21/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include "Person.h"

int main() {
   Person mabuse("Dr. Mabuse");
   Person klicko("Witwe Klicko");
   Person holle("Frau Holle");
   mabuse.lerntkennen(klicko);
   holle.lerntkennen(klicko);
   mabuse.bekannteZeigen();
   klicko.bekannteZeigen();
   holle.bekannteZeigen();
}
