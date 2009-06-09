/* cppbuch/loesungen/k4/3/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"IntMenge.h"
#include<iostream>
using namespace std;

int main() {
   cout << "Test einer Menge für int-Werte" << endl;
   IntMenge menge;
   for(int i=5; i > -3; --i) {
      menge.hinzufuegen(i);
   }
   menge.anzeigen();
   for(int i=3; i < 8; ++i) {
      menge.hinzufuegen(i);
   }
   menge.anzeigen();
   cout << "menge.istMitglied(3) " 
        << menge.istMitglied(3) << endl;
   cout << "menge.istMitglied(-11) " 
        << menge.istMitglied(-11) << endl;
   menge.hinzufuegen(-11);
   menge.anzeigen();
   cout << "menge.istMitglied(-11) " 
        << menge.istMitglied(-11) << endl;
   cout << "menge.getMin() =  " 
        <<  menge.getMin() << endl;
   cout << "menge.getMax() =  " 
        <<  menge.getMax() << endl;
   int k = menge.getMin();
   // menge.loeschen();
   while(menge.size() > 0) { // leeren und anzeigen
      size_t vorher = menge.size();
      menge.entfernen(k++);
      if(vorher != menge.size()) { // 1 Element gelöscht
         menge.anzeigen();
      }
   }

}
