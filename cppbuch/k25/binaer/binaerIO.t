/* cppbuch/k25/binaer/binaerIO.t
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef BINAERIO_T
#define BINAERIO_T
#include<ios>
#include<fstream>
#include"IOException.h"

template<typename T>
void schreibeBinaer(const std::string& dateiname, const T* daten, size_t anzBytes) {
   std::ofstream ziel;
   ziel.open(dateiname.c_str(), std::ios::binary|std::ios::out);
   if (!ziel) {
      throw IOException(dateiname);
   }
   ziel.write(reinterpret_cast<const char*>(daten), anzBytes);
   ziel.close();
}

template<typename T>
void liesBinaer(const std::string& dateiname, T* daten, size_t anzBytes) {
   std::ifstream quelle;
   quelle.open(dateiname.c_str(), std::ios::binary|std::ios::in);
   if (!quelle) {
      throw IOException(dateiname);
   }
   quelle.read(reinterpret_cast<char*>(daten), anzBytes);
   quelle.close();
}
#endif
