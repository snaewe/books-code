/* cppbuch/k27/bind/bind1.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include <iostream>
#include<functional>
using std::bind; 
using namespace std::placeholders;

template <class T>      // T muss ein Typ für Funktionsobjekte sein
void aufrufen(T funcObj) { 
   int i1 = 1;
   int i2 = 3;
   int i3 = 5;
   int doppel = funcObj(i1, i2, i3); // Funktionsaufruf über FuncObj-Objekt
   std::cout << doppel << std::endl;
}

int verdoppeln(int i) {
   return 2*i;
}

int main() {
   aufrufen(bind(verdoppeln,  9)); // Funktion an Wert binden
   aufrufen(bind(verdoppeln, _1)); // Funktion an Parameter 1 binden
   aufrufen(bind(verdoppeln, _2)); // Funktion an Parameter 2 binden
   aufrufen(bind(verdoppeln, _3)); // Funktion an Parameter 3 binden
}
