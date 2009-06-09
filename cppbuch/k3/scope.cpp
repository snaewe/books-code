/* cppbuch/k3/scope.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
using namespace std;
int a = 1;                     // überall bekannt, also global

void f1( ) {
     int c = 3;              // nur in {\tt f1()} bekannt, also lokal
     cout << "f1: c= " << c << endl;
     cout << "f1: globales a= " << a << endl;
}

int main() {
    cout << "main: globales a= " << a << endl;

    // cout << "f1: c= " << c; // ist nicht compilierfähig,
    // weil {\tt c} in {\tt main()} unbekannt ist.
    f1( );                      // Aufruf von {\tt f1()}
}
