/* cppbuch/k24/vergleich/mismatch.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<vector>
#include<set>
#include<showSequence.h>
using namespace std;

int main() {
    vector<int> v(8);
    for(size_t i = 0; i < v.size(); ++i) {
        v[i] = 2*i;                 // sortierte Folge
    }
    set<int> s(v.begin(), v.end()); // Set mit v initialisieren
    v[3] = 7;                       // Nichtübereinstimmung erzeugen
    showSequence(v);                // Anzeige
    showSequence(s);

    // Prüfung mit Iterator Paar 'wo'
    pair<vector<int>::iterator, set<int>::iterator>    
          wo = mismatch(v.begin(), v.end(), s.begin());
    if(wo.first == v.end()) {
       cout << "Inhalt der Container stimmt überein." << endl;
    }
    else {
      cout << "Der erste Unterschied (" << *wo.first << " != "
           << *wo.second           << ") wurde an Position "
           << (wo.first - v.begin()) << " gefunden." << endl;
    }
}
