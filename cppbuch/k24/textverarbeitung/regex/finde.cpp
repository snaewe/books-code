/* cppbuch/k24/textverarbeitung/regex/finde.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <fstream>
#include<boost/regex.hpp>
#include<string>
using namespace std;

int main(int argc, char* argv[])  {
   boost::regex::flag_type flags = boost::regex::egrep;
   string gebrauch("Gebrauch: finde.exe [-i] \"regex\" \"dateiname\"" );
   string option;
   int start = 1;
   // Ist die Option -i gesetzt?
   if(4 == argc) {
      option = argv[1];
      if(option != "-i") {
         cerr << "Falsche Option: " << gebrauch << endl;
         return 1;                             // EXIT
      }
      ++start;
      flags |=  boost::regex::icase;    // Klein-/Großschreibung ignorieren
   }
   else if(3 != argc) {
      cout << gebrauch << endl;
      return 2;                                // EXIT
   }
   // Datei durchsuchen
   try {
      boost::regex gesucht(argv[start], flags);
      ifstream quelle(argv[start+1]);
      size_t zeilennr = 0;
      if(!quelle.good()) {
         throw ios::failure("Dateifehler");
        }
      while(quelle.good()) {
         string zeile;
         getline(quelle, zeile);
         ++zeilennr;
         if(boost::regex_search(zeile, gesucht)) {
            cout << zeilennr << ": " << zeile << endl;
         }
      }
   } 
   catch(boost::regex_error& re) {
      cerr << "Regex-Fehler: " << re.what() << endl;
   }
   catch(ios::failure& e) {
      cerr << e.what() << endl;
   }
}

