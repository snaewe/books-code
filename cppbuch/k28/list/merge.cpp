/* cppbuch/k28/list/merge.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<list>
#include"../../include/showSequence.h"
using namespace std;

int main( ) {
    list<int> L1, L2;

    // Listen mit sortierten Zahlen füllen:
    for(int i = 0; i < 5; ++i) {
        L1.push_back(2*i);       // gerade Zahlen
        L2.push_back(2*i+1);     // ungerade Zahlen
    }

    showSequence(L1); // 0 2 4 6 8
    showSequence(L2); // 1 3 5 7 9

    L1.merge(L2);     // merge
    showSequence(L1); // 0 1 2 3 4 5 6 7 8 9
    showSequence(L2); //  (leere Liste)
}
