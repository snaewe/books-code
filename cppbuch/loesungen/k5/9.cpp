/* cppbuch/loesungen/k5/9.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
// Aufgabe:  Ausgabe von Dateien
#include<iostream>
#include<fstream>
using namespace std;

int main( int argc, char* argv[]) { 
   cout << "Dateien ausgeben" << endl;
   if(argc == 1) {
      cout << "Keine Dateinamen in der Kommandozeile gefunden.\n"
         "Gebrauch: " << argv[0]     // Programmname
           << " datei1 datei2 usw." << endl;
      return 0;
   }
   int nr = 0;
   while(argv[++nr] != 0) {
      ifstream quelle;
      quelle.open(argv[nr], ios::binary|ios::in);
      cout << "Datei " << argv[nr];
      if(!quelle) {                   // Fehlerabfrage
         cout << " nicht gefunden." << endl;
         continue;                    // weiter bei while      
      }
      cout << ":" << endl;
      char ch;
      while(quelle.get(ch)) {
         cout << ch;                  // zeichenweise ausgeben
      }
      quelle.close();
   }
}

