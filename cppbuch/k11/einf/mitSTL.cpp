/* cppbuch/k11/einf/mitSTL.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
   const int ANZAHL = 100;
   vector<int> einContainer(ANZAHL);  // Container definieren

   // Container mit beliebigen Werten füllen (hier: gerade Zahlen)
   for(int i = 0; i < ANZAHL; ++i) {
      einContainer[i] = 2*i;
   }

   int zahl = 0;
   while(zahl != -1) {
      cout << " gesuchte Zahl eingeben (-1 = Ende):";
      cin >> zahl;
      if(zahl != -1) {           // weitermachen?
         // std::find() benutzen
         vector<int>::const_iterator position =
            find(einContainer.begin(), // Container-Methoden
                 einContainer.end(), zahl);

         if (position != einContainer.end()) {
            cout << "gefunden an Position "
                 << (position - einContainer.begin()) << endl;
         }
         else {
            cout << zahl << " nicht gefunden!" << endl;
         }
      }
   }
}
