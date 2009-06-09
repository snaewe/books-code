/* cppbuch/k25/binaer/binaerIO.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
// binäres Schreiben und Lesen von Matrizen
#include<cstdlib>
#include<iostream>
#include<algorithm>    // equal()
#include"binaerIO.t"
using namespace std;

int main() {
   const string dateiname("binaerdaten.bin");
   const int ZEILEN  = 10;
   const int SPALTEN =  8;
   double matrix[ZEILEN][SPALTEN];
   // Matrix mit (hier beliebigen) Werten füllen und anzeigen:
   cout << "Matrix:\n";
   for(int i = 0; i < ZEILEN; ++i) {
      for(int j = 0; j < SPALTEN; ++j) {
         matrix[i][j] = i*SPALTEN + j;
         cout << matrix[i][j] << '\t';
      }
      cout << endl;
   }
   cout << endl;
   // Matrix schreiben
   size_t anzahlBytes = ZEILEN*SPALTEN*sizeof(matrix[0][0]);
   try {
      schreibeBinaer(dateiname, matrix, anzahlBytes);
   }
   catch(const IOException& e) {
      cout << e.what() << endl;
      return 1;
   }
   // Kopie anlegen und mit 0 vorbesetzen
   double kopie[ZEILEN][SPALTEN] = {{0}, {0}};
   // Kopie von der Datei einlesen
   try {
      liesBinaer(dateiname, kopie, anzahlBytes);
   }
   catch(const IOException& e) {
      cout << e.what() << endl;
      return 2;
   }
   // Werte vergleichen zum Nachweis des korrekten Schreibens/Lesens
   if(equal(matrix[0], matrix[0] + ZEILEN*SPALTEN, kopie[0])) {
      cout << "Geschriebene und gelesene Daten sind gleich." << endl;
   }
   else {
      cout << "Geschriebene und gelesene Daten sind ungleich!" << endl;
   }
}
