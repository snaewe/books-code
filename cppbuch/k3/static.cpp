/* cppbuch/k3/static.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
using namespace std;

void func( ) {              // zählt die Anzahl der Aufrufe
    static int anz = 0;     // siehe Text
    cout << "Anzahl = " << ++anz << endl;
}

int main() {
   for (int i = 0; i < 6; ++i)  func( );
}
