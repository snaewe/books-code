/* cppbuch/loesungen/k7/3/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"student.h"
#include"prof.h"
#include<iostream>
#include<vector>
using namespace std;

int main() {
   vector<Person*> diePersonen;
   diePersonen.push_back(
                         new StudentIn("Risse", "Felicitas", "635374"));
   diePersonen.push_back(
                         new ProfessorIn("Philippsen", "Nele", "Datenbanken"));
   diePersonen.push_back(
                         new StudentIn("Spillner", "Julian", "123429"));

   cout << "Vornamen: " << endl;
   for(size_t i = 0; i < diePersonen.size(); ++i) {
      cout << diePersonen[i]->getVorname() << endl;
   }

   cout << "toString() ergibt: " << endl;
   for(size_t i = 0; i < diePersonen.size(); ++i) {
      cout << diePersonen[i]->toString() << endl;
   }

   /* Da im obigen Programm Zeiger auf Person verwendet werden,
      erfordert ein Zugriff auf Methoden, die nicht in Person
      deklariert sind, eine Typumwandlung. Beispiel: */

   cout << "Die Matrikelnummer von " 
        << diePersonen[0]->getNachname() << " ist "
        << ((StudentIn*)diePersonen[0])->getMatrikelnummer() // !
        << endl;
   /* Die Typumwandlung in den Typ StudentIn*
      funktioniert natürlich nur, wenn man genau weiß, dass der
      Zeiger an der Stelle 0 auf ein Objekt des dynamischen Typs
      StudentIn verweist. 
      Was aber, wenn man es nicht genau weiß? Dazu geben die Abschnitte
      'Standard-Typumwandlungsoperatoren' und 
      'Typinformationen zur Laufzeit' Auskunft
*/

}
