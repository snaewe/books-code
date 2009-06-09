/* cppbuch/loesungen/k7/2/main.cpp
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
}
