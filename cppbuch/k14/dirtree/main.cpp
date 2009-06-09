/* cppbuch/k14/dirtree/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<string>
#include"tree.h"
using namespace std;

int main(int argc, char*argv[]) {
   if(argc > 2) {
      cout << "Verzeichnisbaum anzeigen\n"
         "Gebrauch: tree.exe [name]" << endl;
   }
   else {
      string verz("."); // aktuelles Verzeichnis
      if(argc > 1) {
         verz = argv[1];
      }
      try {
         baumAnzeigen(verz);
      }
      catch(const exception& e) {
         cerr << argv[1] << ": Fehler: " << e.what() << endl;
      }
   }
}
