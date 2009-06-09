/* cppbuch/k25/files/boost/verzeichnisanzeigen.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<boost/filesystem/operations.hpp>
#include<iostream>
#include<string>
using namespace std;
namespace bf=boost::filesystem; // zur Abkürzung

int main(int argc, char*argv[]) {
   if(argc > 2) {
      cout << "Verzeichnis anzeigen\n"
         "Gebrauch: verzeichnisanzeigen.exe [name]" << endl;
   }
   else {
      string verz("."); // aktuelles Verzeichnis
      if(argc > 1) {
         verz = argv[1];
      }
      try {
         bf::path pfad(verz);
         bf::directory_iterator di(pfad), ende;
         while(di != ende) {
            bf::path p = di->path();
            bf::file_status status = di->status();
            //cout << p.filename() << '\t'; boost 1.36
            cout << p.file_string() << '\t';
            if(bf::is_directory(status)) {
               cout << " (Verzeichnis)";
            }
            else {
               cout << bf::file_size(p) << " Bytes";
            }
            time_t t = bf::last_write_time(p);
            cout << '\t' << ctime(&t);
            ++di;
         }
      }
      catch(const exception& e) {
         cerr << "Anzeige des Verzeichnisses " << argv[1] 
              << " fehlgeschlagen: " << e.what() << endl;
      }
   }
}
