/* cppbuch/k9/datum/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"datum.h"
#include<iostream>
using namespace std;

int main() {
   cout << "NOCH NICHT VOLLSTÄNDIG (s. Übungsaufgaben)" << endl;
  Datum einDatum;
  ++einDatum;
  cout << "implizite Typumwandlung: ";
  string einString = einDatum;
  cout << einString << endl;

}
