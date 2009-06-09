/* cppbuch/loesungen/k5/10.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
// Aufgabe   Ausgabe von Namen in einer Datei
#include<iostream>
#include<fstream>
using namespace std;

bool istBuchstabe(char c) {
   return (c >= 'A' && c <= 'Z')
       || (c >= 'a' && c <= 'z')
       || c == '_';
}

bool istAlphanumerisch(char c) {
   return (c >= '0' && c <= '9')
      || istBuchstabe(c);
}

int main( int argc, char* argv[]) { 
   if(argc == 1) {
      cout << "Kein Dateiname in der Kommandozeile gefunden.\n"
         "Gebrauch: " << argv[0]     // Programmname
           << " dateiname" << endl;
      return 0;
   }

   ifstream quelle(argv[1]);
   if(!quelle) {                   // Fehlerabfrage
      cout  << "Datei " << argv[1] 
            << " nicht gefunden." << endl;
      return 0;
   }

   char ch;
   bool namengefunden = false;
   while(quelle.get(ch)) {
      if(istBuchstabe(ch)) {
         cout << ch;
         namengefunden = true;
      }
      else if(namengefunden && istAlphanumerisch(ch)) {
         cout << ch;
      }
      else if(namengefunden) {
         namengefunden = false;
         cout << endl;
      }
   }
   quelle.close();
}
