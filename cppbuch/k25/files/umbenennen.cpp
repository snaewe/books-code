/* cppbuch/k25/files/umbenennen.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<cstdio>
#include<cerrno>     // errno
#include<cstring>    // strerror(int)
#include<iostream>
using namespace std;

int main(int argc, char*argv[]) {
   if(argc != 3) {
      cout << "Datei oder Verzeichnis umbenennen\n"
         "Gebrauch: umbenennen.exe altername neuername" << endl;
   }
   else {
      if(rename(argv[1], argv[2]) != 0) {
         cerr << "Umbenennen von " << argv[1] 
              << " fehlgeschlagen: " << strerror(errno) << endl;
      }
   }
}
