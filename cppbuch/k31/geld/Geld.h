/* cppbuch/k31/geld/Geld.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>

class Geld {
 public:
  Geld(long int b = 0L); 
  long int getBetrag() const;
 private:
   long int betrag;
};

std::istream& operator>>(std::istream& is, Geld& G);
std::ostream& operator<<(std::ostream& os, const Geld& G);


