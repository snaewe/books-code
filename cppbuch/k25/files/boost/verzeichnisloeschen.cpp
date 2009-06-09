/* cppbuch/k25/files/boost/verzeichnisloeschen.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<boost/filesystem/operations.hpp>
#include<iostream>
#include<string>
using namespace std;
namespace bf=boost::filesystem;  // Abkürzung

int main(int argc, char*argv[]) {
   if(argc != 2) {
      cout << "Unterverzeichnis loeschen\n"
         "Gebrauch: verzeichnisloeschen.exe name" << endl;
   } else if(argv[1][0] == '.') {
      cout << ". nicht erlaubt. Nur für Unterverzeichnis aufrufen!\n";
   }
   else {
      try {
         bf::path pfad(argv[1]);
         if(bf::exists(pfad) &&  bf::is_directory(pfad)) {
            bf::remove_all(pfad);
         }
         else {
            cout << "Unterverzeichnis " << argv[1] << " existiert nicht!\n";
         }
      }
      catch(const exception& e) {
         cerr << "Loeschen des Verzeichnisses " << argv[1] 
              << " fehlgeschlagen: " << e.what() << endl;
      }
   }
}
