/* cppbuch/k9/new/new/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"Person.h"

using namespace std;

int main() {
   Person person("Lena");                // Stack-Objekt
   cout << "Name : " << person.getName() << endl;
   Person* ptr1 = new Person("Jens");    // Heap-Objekt
   cout << "Name : " << ptr1->getName() << endl;
   delete ptr1;              // Löschen des Heap-Objekts

   size_t anz = 2;
   Person* arr = new Person[anz];   // dynamisches Array anlegen
   for(size_t i = 0; i < anz; ++i) {
      cout << i << ": " << arr[i].getName() << endl;
   }
   delete[] arr;                 // dynamisches Array löschen
}
