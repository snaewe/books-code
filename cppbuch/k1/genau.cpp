/* cppbuch/k1/genau.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include <iostream>
using namespace std;

int main() {
     float a = 1.234567E-7, b = 1.000000, c = -b, s1, s2;
     s1 = a + b;
     s1 += c;                // entspricht {\tt s1 = s1 + c;}
     s2 = a;
     s2 += b + c;
     cout << s1 << '\n';     // 1.192e-7
     cout << s2 << '\n';     // 1.234e-7
}
