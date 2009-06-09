/* cppbuch/k24/vermischtes/regex/datumpruefen.cpp
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

inline bool istSchaltjahr(int jahr)  {
   return  (jahr % 4 == 0 && jahr % 100) || jahr % 400 == 0;
}

bool istGueltigesDatum(int t, int m, int j) {
   // Tage pro Monat(static vermeidet Neuinitialisierung):
   static int tmp[]={31,28,31,30,31,30,31,31,30,31,30,31};
   int letzterTagImMonat = tmp[m-1];
   if(m == 2 && istSchaltjahr(j)) {
      letzterTagImMonat = 29;
   }
   return (   m >= 1    && m <= 12
              && j  >= 1583 && j  <= 2399  // oder mehr
              && t  >= 1    && t   <= letzterTagImMonat);
}


bool datumok(const std::string& eingabe) {
   boost::regex datumregex("\\d\\d?\\.\\d\\d?\\.\\d\\d\\d\\d");
   bool ergebnis =  boost::regex_match(eingabe, datumregex);
   if(ergebnis) { // Syntax ok, Inhalt prüfen
      std::vector<std::string> v; 
      boost::split(v, eingabe, boost::is_any_of("."));
      ergebnis = istGueltigesDatum(boost::lexical_cast<int>(v[0]),
                                boost::lexical_cast<int>(v[1]),
                                boost::lexical_cast<int>(v[2]));
   }
   return ergebnis;
}

using namespace std;

int main(int argc, char* argv[])  {
   if(2 != argc) {
      cout << "Gebrauch: datumpruefen.exe \"Datumstring, z.B. tt.mm.jjjj\"" << endl;
   }
   else {
      try {
         if(datumok(argv[1])) {
            cout << argv[1] << " ist ein gültiges Datum." << endl;
         }
         else {
            cout << argv[1] << " ist kein gültiges Datum." << endl;
         }
      } catch(boost::regex_error& re) {
         cerr << "Fehler: " << re.what() << endl;
      }
   }
}
