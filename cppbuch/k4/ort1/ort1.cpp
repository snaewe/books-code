/* cppbuch/k4/ort1/ort1.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"ort1.h"
#include<iostream>
using namespace std;

int Ort1::getX() const { return xKoordinate;}

int Ort1::getY() const { return yKoordinate;}

void Ort1::aendern(int x, int y) {
   xKoordinate = x;
   yKoordinate = y;
   cout << "Ort1-Objekt geändert! x = "
             <<  xKoordinate << " y = " 
             <<  yKoordinate << endl;
}
