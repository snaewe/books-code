/* cppbuch/k25/files/verzanlegen.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<cstdio>
#include<cerrno>     // errno
#include<cstring>    // strerror(int)
#include<iostream>
#ifdef WIN32
 #include<direct.h>
#else
 #include<sys/stat.h>
#endif

using namespace std;

int main(int argc, char*argv[]) {
   if(argc != 2) {
      cout << "Verzeichnis anlegen\n"
         "Gebrauch: verzanlegen.exe name" << endl;
   }
   else {
#ifdef WIN32
     int fehler = mkdir(argv[1]);
#else
     int fehler = mkdir(argv[1], 0755);
#endif
      if(fehler != 0) {
         cerr << "Anlegen des Verzeichnisses " << argv[1]
              << " fehlgeschlagen: " << strerror(errno) << endl;
      }
   }
}
