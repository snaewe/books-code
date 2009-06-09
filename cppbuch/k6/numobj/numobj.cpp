/* cppbuch/k6/numobj/numobj.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
// Implementation der Klasse  NummeriertesObjekt
#include<iostream>
#include"numobj.h"
#include<cassert>
using std::cout;
using std::endl;

// Initialisierung und Definition der klassenspezifischen Variablen:
int           NummeriertesObjekt::anz       = 0;
unsigned long NummeriertesObjekt::maxNummer = 0L;
bool          NummeriertesObjekt::testmodus = false;

// Default-Konstruktor
NummeriertesObjekt::NummeriertesObjekt()
   :  serienNr(++maxNummer) {
   ++anz;
   if (testmodus) {
      if (serienNr == 1) {
         cout << "Start der Objekterzeugung!\n";
      }
      cout << "  Objekt Nr. "
           << serienNr << " erzeugt" << endl;
   }
}
// Kopierkonstruktor
NummeriertesObjekt::NummeriertesObjekt(const NummeriertesObjekt& nobj)
   :  serienNr(++maxNummer) {
   ++anz;

   if (testmodus) {
      cout << "  Objekt Nr. " << serienNr
           << " mit Nr. "  << nobj.seriennummer()
           << " initialisiert" << endl;
   }
}

// Destruktor
NummeriertesObjekt::~NummeriertesObjekt() {
   anz--;
   if (testmodus) {
      cout << "  Objekt Nr. "
           << serienNr << " gelöscht" << endl;

      if (anz == 0) {
         cout << "letztes Objekt gelöscht!" << endl;
      }
      if (anz < 0) {
         cout << " FEHLER! zu oft delete aufgerufen!"
              << endl;
      }
   }
   else {
      assert(anz >= 0);
   }
}  // Ende von numobj.cpp
