/* cppbuch/k25/files/boost/tree/tree.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<stdexcept>
#include<boost/filesystem/operations.hpp>
#include"tree.h"

namespace bf=boost::filesystem;

namespace {
   void baumAnzeigen(const bf::path& p, int level) {
      bf::directory_iterator di(p),  ende;
      while(di != ende) {
         for(int i = 0; i < level; ++i) {
            std::cout << " |  ";
         }
         //std::cout << " |-- " << di->path().file_string() << std::endl; vor boost 1.36
         std::cout << " |-- " << di->filename() << std::endl;
         if(bf::is_directory(di->status())) {
            baumAnzeigen(di->path(), level+1);
         }
         ++di;
      }
   }
}  // anonymer namespace

void baumAnzeigen(const std::string& verz) {
   bf::path pfad(verz);
   if(bf::is_directory(pfad)) {
      //std::cout << pfad.file_string() << std::endl;  // vor boost 1.36
      std::cout << pfad.filename() << std::endl;  // filename() ab boost 1.36
      baumAnzeigen(pfad, 0);
   }
   else {
      throw std::runtime_error(" ist kein Verzeichnis!");
   }
}
