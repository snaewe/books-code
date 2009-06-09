/* cppbuch/loesungen/k1/5.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
//  Zahl binär ausgeben
#include<iostream>
using namespace std;

int main() {
   cout << "Eingabe einer Zahl: ";
   int zahl = 0;
   cin >> zahl;
   int anzahlDerBytes = sizeof zahl;   
   int anzahlDerBits = 8 * anzahlDerBytes;
   cout <<" binär :  ";
   for(int k = anzahlDerBits-1; k >= 0 ; --k) {
      if(zahl & (1 << k)) {
         cout << "1";
      }
      else {
         cout << "0";
      }
   }
   cout << endl;
}
