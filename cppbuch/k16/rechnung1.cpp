/* cppbuch/k16/rechnung1.cpp
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
   try {
      Datenbank db("shopdb.db");
      Array2d<std::string> rechnungen = db.execute("select * from Rechnung");
      // z=1: Ueberschrift ausblenden
      for(int z = 1; z < rechnungen.getZeilen(); ++z) {
         std::string abfrage("select Name,Id from Kunde where Kunde.Id ="
                             " (select Kundennr from Rechnung where "
                             "Rechnung.Kundennr=Kunde.Id and Rechnung.Id=");
         abfrage +=  rechnungen[z][0] + ");";
         // Kunde zur Rechnung ermittel
         Array2d<std::string> kunde = db.execute(abfrage);
         if(kunde.getZeilen() > 1) { // Kunde existiert, kein Barverkauf
            std::cout << "Herrn/Frau/Firma " << kunde[1][0] // Name
                      << std::endl;
            // Adresse des Kunden ermitteln
            abfrage = "select Plz, Ort, StrNr from Adresse where " 
               "(select Id from Kunde where Kunde.AdressId=Adresse.Id "
               " and Id=" + kunde[1][1] + ");";
            Array2d<std::string> adresse = db.execute(abfrage);
            std::cout << adresse[1][2] <<  std::endl  // Strasse Hausnr
                      << adresse[1][0] << " " << adresse[1][1] // PLZ Ort
                      << "\n\n\nRechnung Nr. " << rechnungen[z][0] 
                      << "  vom " << rechnungen[z][1]  << std::endl;                    
            // Rechnungspositionen ermitteln (View nutzen)
            abfrage = "select * from  positionen where Rechnungsnr="
               + rechnungen[z][0] + ";";
            Array2d<std::string> positionen = db.execute(abfrage);
            // Positionen ausgeben
            std::cout << "Pos. Menge   Artikelnr.        Bezeichnung "
               "Einzelpreis Gesamtpreis"  << std::endl; 
            enum Positionen {NR, ARTNR, MENGE, BEZ, EPREIS, GPREIS};
            // p=1: Ueberschrift ausblenden
            for(int p = 1; p < positionen.getZeilen(); ++p) {
               std::cout.width(4);
               std::cout << p;
               std::cout.width(6);
               std::cout << positionen[p][MENGE];
               std::cout.width(12);
               std::cout << positionen[p][ARTNR];
               std::cout.width(20);
               std::cout << positionen[p][BEZ];
               std::cout.width(12);
               std::cout << formatPreis(positionen[p][EPREIS]);
               std::cout.width(12);
               std::cout << formatPreis(positionen[p][GPREIS]) << std::endl;
            }
            // Summe bilden
            abfrage = "select sum(Preis*Menge) from  positionen where "
                      "Rechnungsnr=" + rechnungen[z][0] + ";";
            Array2d<std::string> summe = db.execute(abfrage);
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
