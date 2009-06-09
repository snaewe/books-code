/* cppbuch/k24/folgen/unique.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
#include<showSequence.h>

using namespace std;

int main() {
    vector<int> v(20);
    // Folge mit benachbarten gleichen Elementen
    for(size_t i = 0; i < v.size(); ++i) {
        v[i] = i/3;
    }
    showSequence(v);         // 0 0 0 1 1 1 2 2 2 3 3 3 4 4 4 5 5 5 6 6
    // Voraussetzung: Container ist sortiert
    vector<int>::iterator last = unique(v.begin(), v.end());
    showSequence(v);         // 0 1 2 3 4 5 6 2 2 3 3 3 4 4 4 5 5 5 6 6
    v.erase(last, v.end());
    showSequence(v);         // 0 1 2 3 4 5 6
}
