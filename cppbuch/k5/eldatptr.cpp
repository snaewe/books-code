/* cppbuch/k5/eldatptr.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
using namespace std;

struct Datensatz {                     // öffentliche Klasse
   Datensatz(int x, int y)
      : a(x), b(y) {}
   int a;
   int b;
};

int main() {
   // Zeiger auf Elementattribute
   Datensatz einDatensatz(1, 2);
   int Datensatz::*dp = &Datensatz::a;

   cout << einDatensatz.*dp << endl;  // 1
   dp = &Datensatz::b;                // Zeiger umschalten
   cout << einDatensatz.*dp << endl;  // 2

   // neues Objekt erzeugen
   Datensatz* dPtr = new Datensatz(1000, 2000);
   cout << dPtr->*dp << endl;         // 2000
   delete dPtr;
}
