/* cppbuch/k25/datum/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"datum.h"

using namespace std;

int main() {
  Datum einDatum;
  try {
    cout << "Bitte Datum eingeben: ";
    cin >> einDatum;
    cout << "Eingegeben wurde der " << einDatum << ".\n";
  } catch(const char* e) {
    cout << e << " Abbruch!" << endl;
  }
}
