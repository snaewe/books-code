/* cppbuch/k24/finden/adjacent_find.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<vector>
#include<iostream>
#include<showSequence.h>
using namespace std;

int main() {
    vector<int> v(8);
    for(size_t i = 0; i < v.size(); ++i) {
        v[i] = 2*i;            // gerade
    }
    v[5] = 99;                 // 2 gleiche benachbarte Elemente
    v[6] = 99;
    showSequence(v);  
    vector<int>::const_iterator iter   // finde gleiche Nachbarn
        = adjacent_find(v.begin(), v.end());
    if(iter != v.end()) {
        cout << "Die ersten gleichen benachbarten Zahlen ("
             << *iter  << ") wurden an Position "
             << (iter - v.begin()) << " gefunden." << endl;
    }
    else {
        cout << "Keine gleichen Nachbarn gefunden."  << endl;
    }
}
