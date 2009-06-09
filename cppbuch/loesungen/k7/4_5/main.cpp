/* cppbuch/loesungen/k7/4_5/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"student.h"
#include"prof.h"
#include<iostream>
#include<vector>
#include<typeinfo>
using namespace std;

int main() {
   vector<Person*> diePersonen;
   diePersonen.push_back(
                         new StudentIn("Risse", "Felicitas", "635374"));
   diePersonen.push_back(
                         new ProfessorIn("Philippsen", "Nele", "Datenbanken"));
   diePersonen.push_back(
                         new StudentIn("Spillner", "Julian", "123429"));


   cout << "toString() ergibt: " << endl;
   for(size_t i = 0; i < diePersonen.size(); ++i) {
      cout << diePersonen[i]->toString() << endl;
   }

   cout << "Die Matrikelnummern mit dynamic_cast: " << endl; 
   for(size_t i = 0; i < diePersonen.size(); ++i) {
      cout << diePersonen[i]->getVorname() << ": ";
      StudentIn* ps = dynamic_cast<StudentIn*>(diePersonen[i]);
      if(ps) {
         cout << ps->getMatrikelnummer() << endl;
      }
      else {
           cout << " hat keine Matrikelnummer." << endl;
      }
   }

   cout << endl << "Die Matrikelnummern mit typeid: " << endl; 
   for(size_t i = 0; i < diePersonen.size(); ++i) {
      cout << diePersonen[i]->getVorname();
      if(typeid(StudentIn) == typeid(*diePersonen[i])) {
         cout << ": " 
              << ((StudentIn*)(diePersonen[i]))->getMatrikelnummer() 
              << endl;
      }
      else {
         cout << " (interner Typ: " 
              << typeid(*diePersonen[i]).name()
              << ") hat keine Matrikelnummer." << endl;
      }
   }
}
