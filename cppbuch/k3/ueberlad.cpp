/* cppbuch/k3/ueberlad.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
using namespace std;

double maximum(double x, double y) {
    return x > y ?  x : y;
}

// zweite Funktion gleichen Namens, aber unterschiedlicher Signatur
int maximum(int x, int y) {
   return x > y ?  x : y;
}

int main() {
   double a=100.2, b= 333.777;
   int c=1700, d = 1000;
   cout << maximum(a,b) << endl;  // Aufruf von maximum(double, double)
   cout << maximum(c,d) << endl;  // Aufruf von maximum(int, int)

   const float E = 2.7182, PI = 3.14159;
   cout << maximum(E, PI) << endl;
   cout << maximum(31,'A') << endl;

   cout << maximum(3.1, static_cast<float>(7)) << endl;
   cout << maximum(3.1, static_cast<double>(7)) << endl;
   int x = 66;
   char y = static_cast<char>(x);
   cout << maximum(static_cast<int>(0.1), static_cast<int>(y)) << endl;
   // Voraussetzung: {\tt char} ist {\tt signed char}.
   // Aufgerufen wird {\tt maximum(int, int)}.
   cout << maximum(-1000, static_cast<char>(600)) << endl;  // ergibt 88
   cout << maximum(-1000, static_cast<char>(128)) << endl;  // ergibt -128
   cout << maximum(-1000, static_cast<char>(129)) << endl;  // ergibt -127 usw
}
