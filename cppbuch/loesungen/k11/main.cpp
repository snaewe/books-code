/* cppbuch/loesungen/k11/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<algorithm>
#include"liste.t"
using namespace std;

int main() {
   const int ANZAHL = 10;
   Liste<int> einContainer;  // Container definieren

   // Container mit beliebigen Werten f�llen (hier: gerade Zahlen)
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
   // Liste kopieren
   Liste<int> kopie(einContainer);
   cout << "Kopie: " << endl;
   while(!kopie.empty()) {
      cout << *kopie.begin() << " size()=" <<  kopie.size() << endl;
      kopie.pop_front();
   }
   // Liste zuweisen
   kopie = einContainer;
   cout << "zugewiesene Kopie: " << endl;
   while(!kopie.empty()) {
      cout << *kopie.begin() << " size()=" <<  kopie.size() << endl;
      kopie.pop_front();
   }

}

