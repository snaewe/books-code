/* cppbuch/k24/vermischtes/regex/datumsyntaxpruefen.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include <iostream>
#include<boost/regex.hpp>
#include<string>

bool datumok(const std::string& eingabe) {
   boost::regex datumregex("\\d\\d?\\.\\d\\d?\\.\\d\\d\\d\\d");
   return boost::regex_match(eingabe, datumregex);
}

using namespace std;

int main(int argc, char* argv[])  {
   if(2 != argc) {
      cout << "Gebrauch: datumsyntaxpruefen.exe \"Datumstring, z.B. tt.mm.jjjj\"" << endl;
   }
   else {
      try {
         if(datumok(argv[1])) {
            cout << argv[1] << " ist ein syntaktisch gültiges Datum." << endl;
         }
         else {
            cout << argv[1] << " ist kein gültiges Datum." << endl;
         }
      } catch(boost::regex_error& re) {
         cerr << "Fehler: " << re.what() << endl;
      }
   }
}
