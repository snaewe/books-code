/* cppbuch/loesungen/k9/6_7/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"meinstring.h"
#include<iostream>
using namespace std;

int main() {
   MeinString einString("Hallo");

   cout << "\nzeichenweise Ausgabe mit at():\n";
   for(size_t i = 0; i < einString.length(); ++i)
      cout << '*' << einString.at(i);
   cout << '*' << endl;
   cout << "\nzeichenweise Ausgabe mit []:\n";
   for(size_t i = 0; i < einString.length(); ++i)
      cout << '*' << einString.at(i);
   cout << '*' << endl;
   // Zuweisen 
   MeinString zweiterString;
   zweiterString = einString;
   cout << "zugewiesener String, Ausgabe mit operator<<: " 
        << endl << zweiterString << endl;
   zweiterString[1] = 'e';
   cout << "operator[](1) ='e': " 
        << endl << zweiterString << endl;

   MeinString verkettet = einString + zweiterString;
   cout << "verkettet: " << verkettet << endl;
}
