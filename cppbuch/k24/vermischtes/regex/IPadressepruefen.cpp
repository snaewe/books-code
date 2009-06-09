/* cppbuch/k24/vermischtes/regex/IPadressepruefen.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include <iostream>
#include<boost/regex.hpp>
#include<boost/lexical_cast.hpp>
#include<boost/algorithm/string/split.hpp>
#include<boost/algorithm/string/classification.hpp>
#include<string>
#include<vector>

bool ipok(const std::string& eingabe) {
   boost::regex datumregex("(?:\\d\\d?\\d?\\.){3}\\d\\d?\\d?");
   bool ergebnis =  boost::regex_match(eingabe, datumregex);
   if(ergebnis) { // Syntax ok, Inhalt prüfen
      std::vector<std::string> v; 
      boost::split(v, eingabe, boost::is_any_of("."));
      for(size_t i = 0; i < v.size(); ++i) {
         ergebnis = ergebnis && boost::lexical_cast<int>(v[i]) < 256;
      }
   }
   return ergebnis;
}

using namespace std;

int main(int argc, char* argv[])  {
   if(2 != argc) {
      cout << "Gebrauch: IPadressepruefen.exe \"IP-Adresse, z.B. 127.0.0.1\"" << endl;
   }
   else {
      try {
         if(ipok(argv[1])) {
            cout << argv[1] << " ist eine gültige IP-Adresse." << endl;
         }
         else {
            cout << argv[1] << " ist keine gültige IP-Adresse." << endl;
         }
      } catch(boost::regex_error& re) {
         cerr << "Fehler: " << re.what() << endl;
      }
   }
}
