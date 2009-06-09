/* cppbuch/k1/union.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
using namespace std;

union HiLo {
    int zahl;
    unsigned char c[sizeof(int)];
};

int main() {
    HiLo was;
    do {
       cout << " Zahl eingeben (0 = Ende):";
       cin >> was.zahl;
       cout << "Byte-weise Darstellung von "
            << was.zahl << endl;
       for(int i = sizeof(int)-1; i >= 0; --i) {
           cout << "Byte Nr. " << i << " = "
                << static_cast<int>(was.c[i])  << endl;
       }
    } while(was.zahl);
}
