/* cppbuch/k24/finden/adjacent_find_1.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<vector>
#include<iostream>
#include<showSequence.h>
using namespace std;

class IstDoppeltSoGross {
public:
   bool operator()(int a, int b) { return (b == 2*a);}
};

int main() {
   vector<int> v(8);
   for(size_t i = 0; i < v.size(); ++i) {
      v[i] = i*i;
   }
   v[6] = 2 * v[5];       // doppelt so großer Nachfolger
   showSequence(v);
   vector<int>::const_iterator iter
      = adjacent_find(v.begin(), v.end(), IstDoppeltSoGross());

   if(iter != v.end()) {
      cout << "Die erste Zahl ("  << *iter
           << ") mit einem doppelt so großen Nachfolger"
         " wurde an Position " << (iter - v.begin())
           << " gefunden." << endl;
   }
   else {
      cout << "Keine Zahl mit einem doppelt so großen Nachfolger gefunden." << endl;
   }
}
