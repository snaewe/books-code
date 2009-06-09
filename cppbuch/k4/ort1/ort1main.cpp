/* cppbuch/k4/ort1/ort1main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"ort1.h"
#include<iostream>
using namespace std;

int main() {
   Ort1 einOrt1;
   einOrt1.aendern(100, 200);
   cout << "Der Ort hat die Koordinaten x = "
        << einOrt1.getX() << " und y = "
        << einOrt1.getY() << endl;
}
