/* cppbuch/k24/random/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>         
#include<vector>
#include<showSequence.h>
#include"Random.h"
using namespace std;

int main() {
   Random zufall;
   for(int i=0; i < 5; ++i) { // 5 Zufallszahlen zwischen 0 und 999 ausgeben
      cout << zufall(1000) << endl;
   }
}
