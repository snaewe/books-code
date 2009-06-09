/* cppbuch/k24/sortieren/mergesort_vec.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<showSequence.h>
#include<vector>
#include"mergesort.t"
#include<Random.h>
using namespace std;

int main() {
    vector<int> v, buffer(20);
    Random zufall;
    for(size_t i = 0; i < 20; ++i) {
       v.push_back(zufall(1000));      // pseudo-zufällige Zahlen 
    }
    showSequence(v);     // pseudo-zufällige Zahlen
    // sortieren und anzeigen
    mergesort(v.begin(), v.end(), buffer.begin());
    showSequence(v);     // sortierte Zahlen
}
