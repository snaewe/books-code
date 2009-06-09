/* cppbuch/loesungen/k9/8_bis_13/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"datum.h"
using namespace std;

int main() {
  Datum einDatum;
  cout << einDatum << endl;
  ++einDatum;
  cout << einDatum << endl;

  Datum heute, irgendwann;
  irgendwann.maxDatum();  // maximales Systemdatum ermitteln
  cout << "Auf diesem System ist das maximale Datum der ";
  cout << irgendwann << '.' << endl;
  cout << "Bis dahin sind es noch "
       << datumDifferenz(heute, irgendwann)
       << " Tage.\n";
  Datum zweitausend(1,1,2000);
  int diff = datumDifferenz(heute, zweitausend);
  if(diff >0)
     cout << "Bis zum " << zweitausend
          << " sind es noch "  << diff << " Tage.\n";
  else
     cout << "Seit dem " << zweitausend
          << " vergingen "  << -diff << " Tage.\n";

  cout << "toString(): ";
  cout << zweitausend.toString() << endl;
}
