/* cppbuch/k1/roemzif1.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
// Umwandlung römischer Ziffern
#include <iostream>
using namespace std;

int main( ) {
   int a = 0;
   char c;
   cout << "Zeichen ?";
   cin >> c;

   if (c == 'I') a = 1;
   else if (c == 'V') a = 5;
   else if (c == 'X') a = 10;
   else if (c == 'L') a = 50;
   else if (c == 'C') a = 100;
   else if (c == 'D') a = 500;
   else if (c == 'M') a = 1000;

   if (a == 0) { 
      cout << "keine römische Ziffer!\n";
   }
   else {
      cout << a << endl;
   }
}
