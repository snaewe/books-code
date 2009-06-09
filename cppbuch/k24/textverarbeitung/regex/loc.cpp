/* cppbuch/k24/textverarbeitung/regex/loc.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
// Nach einer Idee in IEEE Software May/June 2007 p74-79
// dort leider fehlerhaft in Java implementiert.
#include <algorithm>
#include <iostream>
#include <fstream>
#include<boost/regex.hpp>
#include<string>

int zaehleLOC(const char* dateiname) {
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
   // Zeilenendekennung vereinheitlichen
   alles = boost::regex_replace(alles, boost::regex("(\r\n)"), "\n");
   // Leer- und Tabulatorzeichen entfernen
   alles = boost::regex_replace(alles, boost::regex("( |\t)"), "");
   // Escape-Zeichen loeschen
   alles = boost::regex_replace(alles, boost::regex("\\\\."), ""); 

   // Alle Strings durch "" nicht-greedy ersetzen
   alles = boost::regex_replace(alles, boost::regex("\".*?\""), "\"\"");

   // alle /* enthaltenen // Kommentare ersetzen. Leerzeichen
   // muss sein, um nicht auf // /** -> //* reinzufallen
   alles = boost::regex_replace(alles, boost::regex("//[^\n]*/\\*"), "// ");

   // mit /*  beginnenden Kommentare loeschen
   alles = boost::regex_replace(alles, boost::regex("(?s)/\\*.*?\\*/"), "");

   // alle // Kommentare loeschen
   alles = boost::regex_replace(alles, boost::regex("//[^\n]*"), "");
                                
   // Fuehrende Whitespaces entfernen. 
   // Damit werden auch Leerzeilen entfernt (\n am Zeilenanfang)
   alles = boost::regex_replace(alles, boost::regex("^\\s+"), "");

   // Anzahl der Zeilen zurückgeben
   return 1 + std::count(alles.begin(), alles.end(), '\n');
}

using namespace std;

int main(int argc, char* argv[])  {
   string gebrauch("Gebrauch: loc.exe dateiname" );
   if(2 != argc) {
      cout << gebrauch << endl;
      return 1;                                // EXIT
   }
   // Datei analysieren
   try {
      cout << "Die Datei " <<  argv[1] << " hat "
           << zaehleLOC(argv[1]) << " Lines of Code (LOC)." << endl;
   } 
   catch(boost::regex_error& re) {
      cerr << "Regex-Fehler: " << re.what() << endl;
   }
   catch(ios::failure& e) {
      cerr << e.what() << endl;
   }
}
