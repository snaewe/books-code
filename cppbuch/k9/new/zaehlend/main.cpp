/* cppbuch/k9/new/zaehlend/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"Person.h"
using namespace std;

int main() {
   Person person("Lena");
   cout << "Name : " << person.getName() << endl;
   ZaehlendesObjekt::status();
   Person* ptr1 = new Person("Jens");
   cout << "Name : " << ptr1->getName() << endl;
   ZaehlendesObjekt::status();
   delete ptr1;
   ZaehlendesObjekt::status();
}
