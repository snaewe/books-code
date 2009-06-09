/* cppbuch/k14/dirtree/tree.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<stdexcept>
#include<QFileInfo>
#include<QFileInfoList>
#include<QDir>
#include"tree.h"

namespace {
    std::ostream& operator<<(std::ostream& os, const QString& qstr) {
      const char* str = qstr.toAscii().constData();
      os << str;
      return os;
   }

   void baumAnzeigen(const QDir& d, int level) {
      QStringList eintraege = d.entryList(
                       QDir::Dirs|QDir::Files|QDir::NoDotAndDotDot);
      QStringList::const_iterator dIterator = eintraege.begin();
      while(dIterator != eintraege.end()) {
         QString fn(*dIterator);
         QString absPfad(d.absolutePath() + "/" + fn);
            for(int i = 0; i < level; ++i) {
               std::cout << " |  ";
            }
            std::cout << " |-- " << fn << std::endl;
            QFileInfo qi(absPfad);
            if(qi.isDir()) {
               QDir dir(absPfad); 
               baumAnzeigen(dir, level+1);
            }
         ++dIterator;
      }
   }
}  // anonymer namespace

void baumAnzeigen(const std::string& verz) {
   QFileInfo pfad(verz.c_str());
   if(pfad.isDir()) {
      std::cout << verz << std::endl; 
      QDir dir(verz.c_str());
      baumAnzeigen(dir, 0);
   }
   else {
      throw std::runtime_error(" ist kein Verzeichnis!");
   }
}
