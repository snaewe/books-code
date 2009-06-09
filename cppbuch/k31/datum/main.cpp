/* cppbuch/k31/datum/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"datum.h"
using namespace std;

int main() {
   Datum einDatum;
   einDatum.set(1,10,1970);
  locale deDE("de_DE");
  cout << " bitte Datum im Format tt.mm.yyyy eingeben:" << endl;
  cin.imbue(deDE);
  cin >> einDatum;
  cout.imbue(deDE);
  cout << "deutsches Format :"  << einDatum << endl; 
  locale enUS("en_US");
  cout.imbue(enUS);
  cout << "US Format        :"  << einDatum << endl; 
  cout << "toString() mit Standard-Locale deDE:"  << einDatum.toString() << endl; 
  cout << "toString() mit Locale enUS         :"  << einDatum.toString(enUS) << endl; 
}
