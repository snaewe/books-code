/* cppbuch/k1/roemzif2.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
using namespace std;

int main() {
   int a = -1;
   char c;
   cout << "Zeichen ?";
   cin >> c;

   switch(c) {
   case 'I'     : a = 1;    break;
   case 'V'     : a = 5;    break;
   case 'X'     : a = 10;   break;
   case 'L'     : a = 50;   break;
   case 'C'     : a = 100;  break;
   case 'D'     : a = 500;  break;
   case 'M'     : a = 1000; break;
   default      : a = 0;
   }
   if (a > 0) {
      cout << "a = " << a;
   }
   else {
      cout <<"keine römische Ziffer!";
   }
   cout << endl;
}
