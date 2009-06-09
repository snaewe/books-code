/* cppbuch/k3/qsum.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
using namespace std;

int qsum(long z) {
   if(z != 0) {  
      int letzteZiffer = z % 10;
      return letzteZiffer+qsum(z/10);            // Rekursion
   }
   else {                     // Abbruchbedingung z == 0
      return 0;
   }
}

int main() {
   cout << "Zahl: ";
   long zahl;
   cin >> zahl;
   cout << "Quersumme = " << qsum(zahl) << endl;
}
