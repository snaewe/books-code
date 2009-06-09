/* cppbuch/k24/folgen/minmax.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<vector>
#include<utility>
#include<showSequence.h>
#include<numeric>
#if  __GNUC__*10+__GNUC_MINOR__ < 44 
#include<ersatziota.h>
#endif
using namespace std;

struct Absolutbetrag {
  bool operator()(int x, int y) {
    return abs(x) < abs(y);
  }
};


bool abskleiner(int x, int y) {
   return abs(x) < abs(y);
}


int main() {
   vector<long> v(10);
   iota(v.begin(), v.end(), -5); // -5 ... +4
   showSequence(v);
    cout << "Minimum: " << *min_element(v.begin(), v.end()) << endl;
    cout << "Maximum: " << *max_element(v.begin(), v.end()) << endl;

    cout << "Minimum des Absolutbetrags mit Funktor: " 
         << *min_element(v.begin(), v.end(), Absolutbetrag()) << endl;
    cout << "Minimum des Absolutbetrags mit Funktion statt Funktor: " 
         << *min_element(v.begin(), v.end(), abskleiner) << endl;

    cout << "Minimum und Maximum mit nur einem Funktionsaufruf: ";

    typedef vector<long>::iterator iter; // zur Abkürzung
    pair<iter, iter> p = minmax_element(v.begin(), v.end());
    cout << *p.first << "  " << *p.second << endl;
}
