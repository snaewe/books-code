/* cppbuch/loesungen/k24/1/formatcode.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include"Codeformatter.h"


using namespace std;

int main(int argc, char* argv[]) {
   if(argc != 2) {
      cerr << "Gebrauch: formatcode eingabe.cpp > ausgabe.cpp" << endl;
      return 1;
   }
   ifstream is(argv[1]);
   if(is) {
      Codeformatter cf(is);
      cf.run();
   }
   else {
      cerr << "Fehler beim Öffnen der Datei!"  << endl;
   }
}
