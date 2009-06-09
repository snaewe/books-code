/* cppbuch/k27/move/move.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"meinstring.h"
#include<iostream>
#include<utility>
using namespace std;

void tauschen(MeinString& a, MeinString& b) {
   MeinString tmp(a);        // Kopierkonstruktor
   a = b;                    // operator=()
   b = tmp;                  // operator=()
}

void tauschen1(MeinString& a, MeinString& b) {
   MeinString tmp(move(a));  // moving Konstruktor
   a = move(b);              // moving operator=()
   b = move(tmp);            // moving operator=()
}

void tauschen2(MeinString&& a, MeinString&& b) {
   MeinString tmp(move(a));  // moving Konstruktor
   a = move(b);              // moving operator=()
   b = move(tmp);            // moving operator=()
}


void func(MeinString&& a, MeinString&& b) {
   tauschen1(a,b);
}

int main() {
   MeinString a("einA");
   MeinString b("einB");
   tauschen(a, b);
   cout << " a = " << a << "   b = "  << b << endl;
   tauschen1(a, b);
   cout << " a = " << a << "   b = "  << b << endl;
   tauschen2(a, MeinString("temporaer"));
   cout << " a = " << a << "   b = "  << b << endl;
}
