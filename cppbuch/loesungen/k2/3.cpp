/* cppbuch/loesungen/k2/3.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
// Aufgabe: Datei hexadezimal ausgeben mit Erweiterung: 
// Buchstaben und Hexcode nebeneinander
// Die Erweiterung kann gelöst werden, wenn das Ergebnis zeilenweise in zwei
// string-Variablen zwischengespeichert wird.
#include <iostream>
#include <cstdlib> // für exit()
#include<string>
#include <fstream>
using namespace std;

int main() {
   ifstream quelle;
   cout << "Dateiname :";
   string Quelldateiname;
   cin >> Quelldateiname;

   quelle.open(Quelldateiname.c_str(), ios::binary|ios::in);
   if (!quelle)    {// muss existieren
      cerr << Quelldateiname
           << " kann nicht geöffnet werden!\n";
      exit(-1);
   }

   unsigned char c;                    // unsigned!
   unsigned int count = 0, low, hi;

   // char ist notwendig, weil get(unsigned char) nicht
   //implementiert ist (GNU C++)
   char cc;
   const int ZEILENLAENGE = 16;
   string buchstaben, hexcodes;
   while (quelle.get(cc)) {
      c = cc;
      low = int(c) & 15;
      hi  = int(c) >> 4;
      // Umsetzung der Werte 0..15 auf ASCII-Zeichen:
      if (low < 10) {
         low += 48;        // '0'...'9'
      }
      else {
         low += 55;        // 'A'...'F'
      }
      if (hi < 10) {
         hi  += 48;
      }
      else {
         hi  += 55;
      }
      hexcodes += char(hi);
      hexcodes += char(low);
      hexcodes += ' ';
      if(c < ' ') { // nicht druckbares Zeichen
         c = '.';
      }
      buchstaben += c;
      ++count;
      count %= ZEILENLAENGE;
      if (count == 0) {
         cout << buchstaben << "   " << hexcodes << endl;
         buchstaben = "";
         hexcodes = "";
      }
   }
   if (count != 0) { // Rest ausgeben
      cout << buchstaben;
      for(size_t i=0; i < (ZEILENLAENGE-count); ++i) {
         cout << ' ';
      }
      cout << "   " << hexcodes << endl;
   }
   cout << endl;
}
