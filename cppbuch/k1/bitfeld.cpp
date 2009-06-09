/* cppbuch/k1/bitfeld.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
using namespace std;

struct Bitfeldstruktur {  
     unsigned int a : 4;  // a und b sind Bitfelder
     unsigned int b : 3;
};

int main() {
     Bitfeldstruktur x;
     x.a = 06;
     x.b = x.a | 03;
     // Umwandlung in \tt{unsigned} und Ausgabe
     cout << x.b << endl;  
}
