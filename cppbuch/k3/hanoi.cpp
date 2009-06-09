/* cppbuch/k3/hanoi.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
using namespace std;

void bewegen(int n, int quelle, int ziel, int zwischen) {
   if (n > 0) {      // Abbruchbedingung: n == 0
      bewegen(n - 1, quelle, zwischen, ziel);  // rekursiver Aufruf
      cout << "Bringe eine Scheibe von " << quelle  
           << " nach " << ziel << endl;
      bewegen(n - 1, zwischen, ziel, quelle);  // rekursiver Aufruf
   }
}

int main() {
   cout << "Türme von Hanoi! Anzahl der Scheiben: ";
   int scheiben;
   cin >> scheiben;
   bewegen(scheiben, 1, 2 ,3);
}
