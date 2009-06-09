/* cppbuch/k9/new/eigene/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"Person.h"

using namespace std;

int main() {
   Person person("Lena");                // Stack-Objekt
   cout << "Name : " << person.getName() << endl;
   cout << "freie Plaetze : " <<  Person::freiePlaetze() << endl;
   Person* ptr1 = new Person("Jens");    // Heap-Objekt
   cout << "Name : " << ptr1->getName() << endl;
   delete ptr1;              // Löschen des Heap-Objekts
   cout << "freie Plaetze : " <<  Person::freiePlaetze() << endl;
   Person* ptr2 = new Person("Otto");    // Heap-Objekt
   cout << "Name : " << ptr2->getName() << endl;
   delete ptr2;              // Löschen des Heap-Objekts
   cout << "freie Plaetze : " <<  Person::freiePlaetze() << endl;
   const int ANZ = 5;
   Person* ptrarr[ANZ];
   for(int i=0; i < ANZ; ++i) {
      string name("Name   ");
      name[5] = '0' +i;
      ptrarr[i] = new Person(name);
      cout << "freie Plaetze : " <<  Person::freiePlaetze() << endl;
   }
   for(int i=0; i < ANZ; ++i) {
      delete ptrarr[i];
      cout << "freie Plaetze : " <<  Person::freiePlaetze() << endl;
   }
}
