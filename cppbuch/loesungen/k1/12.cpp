/* cppbuch/loesungen/k1/12.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<vector>
using namespace std;

int main() { 
   const int MINIMUM = -99;
   const int MAXIMUM = 100;
   const int INTERVALLZAHL = 10;
   const int INTERVALLBREITE = (MAXIMUM-MINIMUM+1)/INTERVALLZAHL;
   int eingabe;
   vector<int> intervalle(INTERVALLZAHL);

   cout << "Bitte Zahlen im Bereich " << MINIMUM
        << " bis " << MAXIMUM << " eingeben:\n";

   cin >> eingabe;
   while(eingabe >= MINIMUM && eingabe <= MAXIMUM) {
      intervalle[(eingabe-MINIMUM) /INTERVALLBREITE]++;
      cin >> eingabe;
   }
   for(int i = 0; i < INTERVALLZAHL; i++) {
      cout << "Intervall "
           << i*INTERVALLBREITE + MINIMUM << " .. "
           << (i+1)*INTERVALLBREITE + MINIMUM -1 << ": "
           << intervalle[i] << endl;
   }
}
