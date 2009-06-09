/* cppbuch/k11/liste/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<algorithm>
#include"liste.t"
using namespace std;

int main() {
   const int ANZAHL = 100;
   Liste<int> einContainer;  // Container definieren

   // Container mit beliebigen Werten füllen (hier: gerade Zahlen)
   for(int i = 0; i < ANZAHL; ++i) {
      einContainer.push_front(2*i);
   }

   int zahl = 0;
   while(zahl != -1) {
      cout << " gesuchte Zahl eingeben (-1 = Ende):";
      cin >> zahl;
      if(zahl != -1) {           // weitermachen?
         // std::find() benutzen
         Liste<int>::iterator position =
            find(einContainer.begin(), // Container-Methoden
                 einContainer.end(), zahl);
         if (position == einContainer.end()) {
            cout << " nicht gefunden!";
         }
         else {
            cout << *position   // Dereferenzierung des Iterators
                << " gefunden!" << endl;
         }
      }
   }
   cout << "Liste ausgeben:" << endl;
   for(Liste<int>::iterator iter = einContainer.begin();
       iter != einContainer.end(); ++iter) {
      cout << *iter << endl;
   }
}

