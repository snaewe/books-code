/* cppbuch/k2/eingabe1.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<string>
using namespace std;

int main() {
   cout << "Bitte Vor- und Nachnamen eingeben:";
   string derName;
   cin >> derName;
   cout << derName;
}
