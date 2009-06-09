/* cppbuch/k27/forward/forward.cpp
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

template <class T>  
A* g(T&&  a) {
   return new A(forward<T>(a));
}


int main() {
   A a;
   A* ptr1 = g(a);     // Kopie erforderlich, g<A&>(a);
   delete ptr1;
   A* ptr2 = g(A());   // Kopie unnötig (move),  g<A>(A());
   delete ptr2;
}

