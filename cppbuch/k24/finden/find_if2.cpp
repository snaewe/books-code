/* cppbuch/k24/finden/find_if2.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<vector>
#include<iostream>
#include<showSequence.h>
#if  __GNUC__*10+__GNUC_MINOR__ < 44 
#include<tr1/functional>
using std::tr1::bind;
using namespace std::tr1::placeholders;
#else
#include<functional>
using std::bind; 
using namespace std::placeholders;
#endif
using namespace std;

int main() {
    vector<int> v(8);

    for(size_t i = 0; i < v.size(); ++i)
        v[i] = 2*i;                     // nur gerade Zahlen
    v[5] = 99;                          // eine ungerade Zahl
    showSequence(v);

    // nach ungerader Zahl suchen
    vector<int>::const_iterator iter
       = find_if(v.begin(), v.end(), bind(modulus<int>(), _1, 2));
       // alter C++-Standard (#include<functional> verwenden)
       // = find_if(v.begin(), v.end(), bind2nd(modulus<int>(),2));
    if(iter != v.end()) {
        cout << "Die erste ungerade Zahl ("  << *iter
             << ") wurde an Position " << (iter - v.begin())
             << " gefunden." << endl;
    }
    else cout << "Keine ungerade Zahl gefunden." << endl;
}
