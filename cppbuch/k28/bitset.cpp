/* cppbuch/k28/bitset.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<bitset>
#include<iostream>
using namespace std;
int main() {
   bitset<15> einBitset;  
   einBitset.set();                 // alles 1
   einBitset[4].flip();             // Bit 4 wird 0
   cout << einBitset << endl;
   einBitset >>= 4;  // Rechtsverschiebung um 4 Positionen
   cout << einBitset << endl;
}
