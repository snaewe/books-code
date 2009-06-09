/* cppbuch/k24/vermischtes/generate.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>         
#include<vector>
#include<showSequence.h>
#include<Random.h>
using namespace std;

int zweierpotenz() { 
   static int wert = 1; //  mit 1 anfangen
   return wert <<= 1;   // Wert verdoppeln
}

int main() {
    vector<int> v(10);
    generate(v.begin(), v.end(), zweierpotenz); 
    showSequence(v); // 2 4 8 16 32 64 128 256 512 1024

    Random zufall(10000);
    generate_n(v.begin(), v.size()/2, zufall); 
    showSequence(v);
}
