/* cppbuch/k16/abfrage.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include"Datenbank.h"

int main(int argc, char **argv){
   std::string zeile;
   std::cout << "Datenbankname: ";
   std::getline(std::cin, zeile); 
   try {
      Datenbank db(zeile.c_str());
      do {
         std::cout << "SQL-Anweisung: ";
         std::getline(std::cin, zeile); 
         if(zeile.length() > 0) {
            printArray(db.execute(zeile.c_str()));
         }
      } while(zeile.length() > 0);
   } catch(const SQLError& e) {
      std::cout << e.what() << std::endl;
   }
}
