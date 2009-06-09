/* cppbuch/loesungen/k4/4/person.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
// Klassendeklaration zur Simulation eines Getränkeautomaten
// Alle Methoden sind inline, weil sie sehr kurz sind.

#ifndef PERSON_H
#define PERSON_H 
#include<iostream>
#include<string>
#include"automat.h"

class Person {
  public:
    Person(int anfaenglicheGeldmenge)       // Konstruktor
    : geld(anfaenglicheGeldmenge) {
        std::cout << "\n Eine Person mit "
             << geld << " Euro kommt." << std::endl;
    }

    ~Person() {                             // Destruktor
        std::cout << " Eine Person geht mit "
             << geld << " Euro." << std::endl;
    }

    bool genugGeld(int preis) const {
        return  preis <= geld;
    }

    int wievielGeld() const  {   return geld; }

    void sagt(const std::string& text) const { 
      std::cout << text << std::endl; 
    }

    void trinkt() const {  sagt(" gluckgluck... aaaah!"); }

    void doseEntnehmen(GetraenkeAutomat& a) const {
          a.doseFreigeben();
    }

    void geldEntnehmen(int muenzen) {
          geld += muenzen;
    }

    void geldEinwerfen(GetraenkeAutomat& a, int muenzen) {
        geld -= muenzen;       // eigenes Geld wird weniger
        a.muenzenAkzeptieren(muenzen);
    }

    void knopfDruecken(GetraenkeAutomat& a) const {
        a.geldPruefenUndDoseHerausgeben();
    }

  private:
    int geld;  // Die wichtigste Eigenschaft von Kunden:
               // sie müssen privates Geld haben ...
};
#endif  // Ende von person.h
