/* cppbuch/loesungen/k1/10.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>

using namespace std;

int main() {
   string str = "17462309"; // aus Aufgabentext
   long int z = 0;
   for(unsigned int i = 0; i < str.size(); ++i) {
      z *= 10;
      z += (int)str.at(i) - (int)'0';
   }
   cout << "z = " << z;
   int quersumme = 0;
   while(z > 0) {
      quersumme += z % 10;
      z /= 10;
   }
   cout << "   Quersumme = " << quersumme << endl;
   return 0;
}
