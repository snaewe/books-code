/* cppbuch/k24/strings/string2zahl.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<cstdlib>
using namespace std;

int main() {
   cout << "Bitte Zahl eingeben: ";
   char eingabe[80];
   cin >> eingabe;
   char* rest;
   double d;
   d = strtod(eingabe, &rest);
   cout << "double-Zahl= " << d << "  Rest= " << rest<< endl;
   long lo = strtol(eingabe, &rest, 10);
   lo = strtol(eingabe, &rest, 2);
   cout << "long-Zahl (2)= " << lo << "  Rest= " << rest << endl;
   cout << "long-Zahl (10)= " << lo << "  Rest= " << rest << endl;
   lo = strtol(eingabe, &rest, 0);
   cout << "long-Zahl (0)= " << lo << "  Rest= " << rest << endl;
   lo = strtol(eingabe, &rest, 16);
   cout << "long-Zahl (16)= " << lo << "  Rest= " << rest << endl;
   lo = strtol(eingabe, &rest, 8);
   cout << "long-Zahl (8)= " << lo << "  Rest= " << rest << endl;
}
