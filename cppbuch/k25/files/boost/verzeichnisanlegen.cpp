/* cppbuch/k25/files/boost/verzeichnisanlegen.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<boost/filesystem/operations.hpp>
#include<iostream>
using namespace std;

int main(int argc, char*argv[]) {
   if(argc != 2) {
      cout << "Verzeichnis anlegen\n"
         "Gebrauch: verzeichnisanlegen.exe name" << endl;
   }
   else {
      try {
         boost::filesystem::create_directory(argv[1]);
      }
      catch(const exception& e) {
         cerr << "Anlegen des Verzeichnisses " << argv[1] 
              << " fehlgeschlagen: " << e.what() << endl;
      }
   }
}
