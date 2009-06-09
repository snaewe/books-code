/* cppbuch/k25/files/loeschen.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<cstdio>
#include<cerrno>     // errno
#include<cstring>    // strerror(int)
#include<iostream>
using namespace std;

int main(int argc, char*argv[]) {
   if(argc != 2) {
      cout << "Datei oder leeres Verzeichnis loeschen\n"
         "Gebrauch: loeschen.exe name" << endl;
   }
   else {
      if(remove(argv[1]) != 0) {
         cerr << "Loeschen von " << argv[1] 
              << " fehlgeschlagen: " << strerror(errno) << endl;
      }
   }
}
