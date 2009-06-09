/* cppbuch/k24/textverarbeitung/csvauswerten.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<string>
#include<cstring>
#include<vector>
#include<cstdlib> // für exit( )
#include<fstream>
#include<iostream>

std::vector<int> splitInt(char* buf, const char* trennzeichen) {
   std::vector<int> vec;
   char* str = strtok(buf, trennzeichen);
   while(str) {
      vec.push_back(atoi(str));
      str = strtok(NULL, trennzeichen);
   }
   return vec;
}

using namespace std;


int main( ) {
   // Definieren der Eingangsdatei
   ifstream quelle;            // Datentyp für Eingabestrom 
   string csvDateiname;
   cout << "CsvDatei? ";
   cin >> csvDateiname;
   quelle.open(csvDateiname.c_str(), ios::in);    // Datei öffnen:
   if (!quelle) {   // Fehlerabfrage
      cerr << csvDateiname  << " kann nicht geöffnet werden!\n";
      exit(-1);
   }
   const size_t N = 1000; 
   char buf[N];         // Muss groß genug für eine Zeile sein
   vector<vector<int> > tabelle;
   while(quelle.good()) {
      quelle.getline(buf, N);
      if(!quelle.fail()) {
         tabelle.push_back(splitInt(buf, ","));
      }
   }
   quelle.close();
   // Tabelle ausgeben
   for(size_t i=0; i < tabelle.size(); ++i) {
      for(size_t j=0; j < tabelle[i].size(); ++j) {
         cout << tabelle[i][j] << "  ";
      }
      cout << endl;
   }
}
