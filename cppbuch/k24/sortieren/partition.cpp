/* cppbuch/k24/sortieren/partition.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<iostream>
#include<vector>
#include<numeric>
#if  __GNUC__*10+__GNUC_MINOR__ < 44 
#include<tr1/functional>
using std::tr1::bind;
using namespace std::tr1::placeholders;
#include<ersatziota.h>
#else
#include<functional>
using std::bind; 
using namespace std::placeholders;
#endif
#include<showSequence.h>

using namespace std;

int main() {
    vector<int> v(12);
    iota(v.begin(), v.end(), -6);
    random_shuffle(v.begin(), v.end());

    vector<int> unstable = v,
                  stable = v;

    // nach altem C++-Standard:
    // \tt{partition(unstable.begin(), unstable.end(), bind2nd(less<int>(),0));}
    // \tt{stable\_partition(stable.begin(), stable.end(), bind2nd(less<int>(),0));}
    // nach neuem C++-Standard \cite{ISO0x}:
    partition(unstable.begin(), unstable.end(), bind(less<int>(), _1, 0));
    stable_partition(stable.begin(), stable.end(), bind(less<int>(), _1, 0));

    cout << "In negative und positive Elemente zerlegen\n";
    cout << "Sequenz vor der Zerlegung :";
    showSequence(v);        // -5 -1 3 2 -3 5 -4 -6 4 0 1 -2

    cout << "stabile Partitionierung   :";
    showSequence(stable);   // -5 -1 -3 -4 -6 -2 3 2 5 4 0 1

    cout << "unstabile Partitionierung :";
    // Die negativen Elemente sind nicht mehr in ihrer ursprünglichen Reihenfolge
    showSequence(unstable); // -5 -1 -2 -6 -3 -4 5 2 4 0 1 3
}
