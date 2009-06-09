/* cppbuch/k9/new/malloc/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"Person.h"

using namespace std;

int main() {
   Person person("Lena");
   cout << "Name : " << person.getName() << endl;
   Person* ptr1 = new Person("Jens");
   cout << "Name : " << ptr1->getName() << endl;
   delete ptr1;
   size_t anz = 4;
   Person* arr = new Person[anz];
   for(size_t i = 0; i < anz; ++i) {
      cout << i << ": " << arr[i].getName() << endl;
   }
   delete[] arr;
}
