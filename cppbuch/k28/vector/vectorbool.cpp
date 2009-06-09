/* cppbuch/k28/vector/vectorbool.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<vector>
#include<iostream>
#include"../../include/showSequence.h"
using namespace std;

int main() {
   vector<bool> vecBool(4, true);  // alles true
   vecBool.flip();                 // alles false
   vecBool[1].flip();              // Bit 1 wird true
   cout.setf(ios_base::boolalpha);
   showSequence(vecBool);
}
