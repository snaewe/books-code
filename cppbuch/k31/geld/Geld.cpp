/* cppbuch/k31/geld/Geld.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"Geld.h"
#include<locale>

Geld::Geld(long int b) 
   :betrag(b){
}

long int Geld::getBetrag() const {
   return betrag;
}

std::istream& operator>>(std::istream& is, Geld& geld) {
   std::istream::sentry s(is);  // {\tt sentry} siehe Seite \pageref{sentry}
   if(s) {
      std::ios_base::iostate fehler = is.rdstate();
      is.setf(std::ios::showbase);  // damit die Währung ausgewertet wird
      long double wieviel = 0;
      std::use_facet<std::money_get<char> >(is.getloc())
         .get(is, 0, false, is, fehler, wieviel);
      is.setstate(fehler);
      if(!fehler) {
         geld = Geld(static_cast<long int>(wieviel));
      }
      else {
         std::cerr << "fehlerhafte Eingabe!\n";
      }
   }
   return is;
}

std::ostream& operator<<(std::ostream& os, const Geld& geld) {
   std::ostream::sentry s(os);
   os.setf(std::ios::showbase);  // damit die Währung angezeigt wird
   if(s) {
      std::use_facet<std::money_put<char> >(os.getloc())
         .put(os, true, os, ' ', static_cast<double>(geld.getBetrag()));
   }
   return os;
}
