/* cppbuch/k1/fakultaet.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
using namespace std;

int main() {
   cout << "Fakultät berechnen. Zahl >= 0? :";
   int n;
   cin >> n;

   unsigned long fak = 1;
   for(int i = 2; i <= n; ++i) {
      fak *= i;
   }
   cout << n << "!   =   " << fak << endl;
}
