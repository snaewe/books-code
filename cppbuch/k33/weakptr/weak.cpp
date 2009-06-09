/* cppbuch/k33/weakptr/weak.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#if  __GNUC__*10+__GNUC_MINOR__ < 44 
#error Die Uebersetzung dieses Programms verlangt mindestens G++ 4.4
#else
#include <iostream>
#include <memory>
using namespace std;

struct A {
   weak_ptr<A> nachbar;
   //shared_ptr<A> nachbar;
   ~A() {
      cout << "Destruktor ~A() aufgerufen" << endl;
   }
};

void f() {
   A* a1 = new A;
   A* a2 = new A;
   a1->nachbar = shared_ptr<A>(a2);
   a2->nachbar = shared_ptr<A>(a1);
}

int main() {
   f();
}

#endif
