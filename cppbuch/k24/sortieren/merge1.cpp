/* cppbuch/k24/sortieren/merge1.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<vector>
#include<showSequence.h>
using namespace std;

int main() {
    vector<int> v(16);                   // gerade Zahl
    int middle = v.size()/2;
    for(int i = 0; i < middle; ++i) {
        v[i]         = 2*i;              // gerade
        v[middle + i] = 2*i + 1;         // ungerade
    }
    showSequence(v);
    inplace_merge(v.begin(), v.begin() + middle, v.end());
    showSequence(v);
}
