/* cppbuch/loesungen/k6/3/teilnehmer.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"teilnehmer.h"
#include<iostream>
using std::cout;
using std::endl;

Teilnehmer::Teilnehmer(const string& n) 
   : name(n) {
}

void Teilnehmer::lerntKennen(Teilnehmer& tn) {
   if(&tn != this // 'sich selbst kennenlernen' ignorieren
      && !kennt(tn)  ) { // wenn noch unbekannt, eintragen
      dieBekannten.push_back(tn.gibNamen());
      tn.lerntKennen(*this); // wechselseitig kennenlernen
   }
}

bool Teilnehmer::kennt(const Teilnehmer& tn) const {
   bool erg = false;
   for(size_t i = 0; i < dieBekannten.size(); ++i) {
      if(tn.gibNamen() == dieBekannten.at(i)) {
         erg = true;
         break;
      }
   }
   return erg;
}

void Teilnehmer::druckeBekannte() const {
   for(size_t i = 0; i < dieBekannten.size(); ++i) {
      cout << "  " << dieBekannten.at(i);
   }
   cout << endl;
}

const string& Teilnehmer::gibNamen() const {
   return name;
}


