/* cppbuch/loesungen/k6/3/party.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"teilnehmer.h"
#include<iostream>
using namespace std;

int main() {
   Teilnehmer otto("Otto");
   Teilnehmer andrea("Andrea");
   Teilnehmer jens("Jens");
   Teilnehmer silvana("Silvana");
   Teilnehmer miriam("Miriam");
   Teilnehmer paul("Paul");
   Teilnehmer* const alle[] = {&otto, &andrea, &jens, &silvana,
                         &miriam, &paul, 0}; // 0 = Endekennung
   andrea.lerntKennen(jens);
   silvana.lerntKennen(otto);
   paul.lerntKennen(otto);
   paul.lerntKennen(silvana);
   miriam.lerntKennen(andrea);
   jens.lerntKennen(miriam);
   jens.lerntKennen(silvana);
   if(jens.kennt(andrea)) {
      cout << "Jens kennt Andrea" << endl;
   }
   int i = 0;
   // Ausgabe aller Teilnehmer mit Angabe, wer wen kennt:
   while(alle[i]) {
      cout << alle[i]->gibNamen() << " kennt: ";
      alle[i]->druckeBekannte();
      ++i;
   }
}
