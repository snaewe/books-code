/* cppbuch/k27/forward/forwardohneTemplate.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<utility>

using namespace std;

struct A {
   A() {}
   A(A& a)  { cout << "hier ist A(A& a) (Kopie)" << endl;}
   A(A&& a) { cout << "hier ist A(A&& a) (move)" << endl;}
};

A* g(A&  a) {
   return new A(a);
}

A* g(A&&  a) {
   return new A(move(a));
}

int main() {
   A a;
   A* ptr1 = g(a);     // Kopie erforderlich
   delete ptr1;
   A* ptr2 = g(A());   // Kopie unnötig (move)
   delete ptr2;
}

