/* cppbuch/k1/overflow.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include <iostream>
using namespace std;

int main() {
   int ai = 50000; int bi = 1000000; int ci = ai*bi;
   cout << "int-Zahlen haben auf Ihrem System " 
        << 8*sizeof(int) << " Bits" << endl;
   cout << "Rechnung mit int: ";
   cout << ai << " * " << bi << " = " << ci << endl;
   // Ausgabe -1539607552 statt 50000000000 bei 32 Bit-int

   long al = 50000; long bl = 1000000; long cl = al*bl;
   cout << "long-Zahlen haben auf Ihrem System " 
        << 8*sizeof(long) << " Bits" << endl;
   cout << "Rechnung mit long: ";
   cout << al << " * " << bl << " = " << cl << endl;

   // Falls Ihr Compiler long long unterstützt:
   long long all = 50000; long long bll = 1000000; 
   long long cll = all * bll;
   cout << "long long-Zahlen haben auf Ihrem System " 
        << 8*sizeof(long long) << " Bits" << endl;
   cout << "Rechnung mit long long: ";
   cout << all << " * " << bll << " = " << cll << endl;
}
