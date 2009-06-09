/* cppbuch/k24/textverarbeitung/regex/ersetze.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <fstream>
#include<boost/regex.hpp>
#include<string>

std::string ersetzeInDatei(const boost::regex& gesucht, 
                           const std::string& ersatz,
                           const char* dateiname) {
   std::ifstream quelle(dateiname, std::ios::binary | std::ios::in);
   if(!quelle.good()) {
      throw std::ios::failure("Dateifehler");
   }
   std::string alles;
   while(quelle.good()) {
      char c = (char)quelle.get();
      if(!quelle.fail()) {
         alles += c;
      }
   }
   return  boost::regex_replace(alles, gesucht, ersatz);
}

using namespace std;

int main(int argc, char* argv[])  {
   boost::regex::flag_type flags = 0;// s.unten icase, falls  gefordert
   string gebrauch("Gebrauch: ersetze.exe [-i] \"regex\" \"ersatz\" \"dateiname\"" );
   string option;
   int start = 1;
   // Ist die Option -i gesetzt?
   if(5 == argc) {
      option = argv[1];
      if(option != "-i") {
         cerr << "Falsche Option: " << gebrauch << endl;
         return 1;                             // EXIT
      }
      ++start;
      flags |=  boost::regex::icase;    // Klein-/Großschreibung ignorieren
   }
   else if(4 != argc) {
      cout << gebrauch << endl;
      return 2;                                // EXIT
   }
   // Datei durchsuchen
   try {
      boost::regex gesucht(argv[start], flags);
      string ersatz(argv[start+1]);
      string ergebnis = ersetzeInDatei(gesucht, argv[start+1], argv[start+2]);
      cout << ergebnis << endl;
   } 
   catch(boost::regex_error& re) {
      cerr << "Regex-Fehler: " << re.what() << endl;
   }
   catch(ios::failure& e) {
      cerr << e.what() << endl;
   }
}
