/* cppbuch/k24/folgen/rotate.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<showSequence.h>
#include<algorithm>
#include<vector>
#include<numeric>
#if  __GNUC__*10+__GNUC_MINOR__ < 44 
#include<ersatziota.h>
#endif
using namespace std;

int main() {
   vector<int> v(10);
   iota(v.begin(), v.end(), 0);

   for(size_t shift = 1; shift < 3; shift++) {
      cout << "Rotation um " << shift << endl;
      for(size_t i = 0; i < v.size()/shift; ++i) {
         showSequence(v);
         rotate(v.begin(), v.begin() + shift, v.end());
      }
   }
   cout << "Rotation mit Kopie:" << endl;
   vector<int> erg(10);
   rotate_copy(v.begin(), v.begin() + 3, v.end(), erg.begin());
   showSequence(erg);
}
