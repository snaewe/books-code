/* cppbuch/k24/finden/find_if.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<vector>
#include<iostream>
#include<showSequence.h>
using namespace std;

class Ungerade {
public:
   bool operator()(int x) { 
      return x % 2 != 0;
   }
};

int main() {
   vector<int> v(8);
   for(size_t i = 0; i < v.size(); ++i) {
      v[i] = 2*i;                     // nur gerade Zahlen
   }
   v[5] = 99;                          // eine ungerade Zahl
   showSequence(v);

   // nach ungerader Zahl suchen
   vector<int>::const_iterator iter
      = find_if(v.begin(), v.end(), Ungerade());
   if(iter != v.end()) {
      cout << "Die erste ungerade Zahl ("  << *iter
           << ") wurde an Position " << (iter - v.begin())
           << " gefunden." << endl;
   }
   else {
      cout << "Keine ungerade Zahl gefunden." << endl;
   }
}
