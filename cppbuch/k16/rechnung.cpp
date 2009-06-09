/* cppbuch/k16/rechnung.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include"Datenbank.h"

namespace {
   // SQL-Zahlen auf 2 dargestellte Nachkommazahlen bringen
   std::string formatPreis(const std::string& s) {
      size_t punkt = s.find('.');
      if(punkt == std::string::npos) {
         return s + ".00";
      } else if(s.length() - punkt == 2) {
         return s + "0";
      }
      return s;
   }
}

int main(int argc, char **argv){
   enum Struktur {NR, DATUM, NAME, PLZ, ORT, STRNR, MENGE, ARTNR,BEZ, EPREIS, GPREIS};
   try {
      Datenbank db("shopdb.db");
      Array2d<std::string> rechnungen = db.execute("select * from alles");
      std::string rechnNr("");
      int z = 1;
      bool rechnungskopfGedruckt = false;
      while(z < rechnungen.getZeilen()){
         int position;
         if(rechnNr != rechnungen[z][NR]) { // neue Rechnung beginnt
            rechnNr = rechnungen[z][NR];
            rechnungskopfGedruckt = false;
         }
         if(rechnungen[z][NAME] != "") {   // Kunde existiert, kein Barverkauf
            if(!rechnungskopfGedruckt) {
               std::cout 
                  << "Herrn/Frau/Firma " << rechnungen[z][NAME] << std::endl
                  << rechnungen[z][STRNR] <<  std::endl
                  << rechnungen[z][PLZ] << " " << rechnungen[z][ORT]
                  << "\n\n\nRechnung Nr. " << rechnNr
                  << "  vom " << rechnungen[z][DATUM]  << std::endl
                  << "Pos. Menge   Artikelnr.        Bezeichnung "
                  "Einzelpreis Gesamtpreis"  << std::endl; 
               rechnungskopfGedruckt = true;
               position = 1; 
            }
            // Positionen ausgeben
            std::cout.width(4);
            std::cout << position++;
            std::cout.width(6);
            std::cout << rechnungen[z][MENGE];
            std::cout.width(12);
            std::cout << rechnungen[z][ARTNR];
            std::cout.width(20);
            std::cout << rechnungen[z][BEZ];
            std::cout.width(12);
            std::cout << formatPreis(rechnungen[z][EPREIS]);
            std::cout.width(12);
            std::cout << formatPreis(rechnungen[z][GPREIS]) << std::endl;
         }
         ++z;
         if(rechnungskopfGedruckt && 
            (z == rechnungen.getZeilen() 
             ||  (z < rechnungen.getZeilen() && rechnNr != rechnungen[z][NR]))) {
            Array2d<std::string> summe 
               = db.execute("select sum(Preis*Menge) from alles where Rechnungsnr=" 
                            + rechnNr + ";");
            std::cout.width(66);
            std::cout << "-----------" << std::endl;
            std::cout.width(66);
            std::cout << formatPreis(summe[1][0]) << std::endl
                      << '\f' << std::endl;  // Seitenvorschub
         }
      }
   } catch(const SQLError& e) {
      std::cout << e.what() << std::endl;
   }
}
