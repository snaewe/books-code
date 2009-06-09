/* cppbuch/k24/folgen/permute.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<showSequence.h>
#include<vector>
#include<numeric>
#if  __GNUC__*10+__GNUC_MINOR__ < 44 
#include<ersatziota.h>
#endif
using namespace std;

long fakultaet(unsigned n) {  // Fakultät $n!$ berechnen
   long fac = 1;
   while(n > 1) {
      fac *= n--;
   }
   return fac;
}

int main() {
   vector<int> v(4);
   iota(v.begin(), v.end(), 0);        // 0 1 2 3  
   long anzahl = fakultaet(v.size());  // Anzahl der Permutationen
   for(int i = 0; i < anzahl; ++i) {
      if(!prev_permutation(v.begin(), v.end())) {
         cout << "Zyklusbeginn:\n";        // siehe Text
      }
      showSequence(v);
   }
}
