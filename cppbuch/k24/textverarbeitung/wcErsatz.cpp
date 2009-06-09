/* cppbuch/k24/textverarbeitung/wcErsatz.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
//  Datei-Statistik
#include<iostream>
#include<locale>
#include<cstdlib> //  exit()
#include<fstream>
#include<cstring>
using namespace std;

void zaehlen(const char* dateiname, size_t& zeilenzahl,
             size_t& wortzahl, size_t& zeichenzahl) {
   ifstream quelle(dateiname);
   if (!quelle) {   // muss existieren
      throw exception();
   }
   char c;
   zeichenzahl = 0, wortzahl = 0, zeilenzahl = 0;
   bool wort = false;

   while (quelle.good() &&  quelle.get(c)) {
      if (c == '\n')  {
         ++zeilenzahl;
      }
      else {
         ++zeichenzahl;
      }
      if (isalpha(c)) { // eingestellte locale wird beruecksichtigt
         wort = true;  // Wortanfang, oder  c ist in einem Wort
      }
      else {
         if(wort) {
            ++wortzahl; // Wortende ueberschritten
         }
         wort = false;
      }
   }
}

int main(int argc, char* argv[]) {
   if(argc != 2) {
      cerr << "Gebrauch: wcErsatz.exe eingabe.txt" << endl;
      return 1;
   }
   locale::global(locale("de_DE"));  //  Umlaute beruecksichtigen

   size_t zeilenzahl, wortzahl, zeichenzahl;
   try {
   zaehlen(argv[1], zeilenzahl, wortzahl, zeichenzahl);
   } catch(...) {
      cerr << "Fehler beim Öffnen der Datei!" << endl;
   }
    cout << "Anzahl der Zeichen (ohne Zeilenendekennung) = " << zeichenzahl << endl;
    cout << "Anzahl der Worte   = " << wortzahl    << endl;
    cout << "Anzahl der Zeilen  = " << zeilenzahl  << endl;
}
