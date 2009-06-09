/* cppbuch/k24/folgen/partialsum.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<numeric>
#include<vector>
#include<showSequence.h>
#if  __GNUC__*10+__GNUC_MINOR__ < 44 
#include<ersatziota.h>
#endif
using namespace std;

int main() {
    vector<long> v(10), partialsummen(10);
    iota(v.begin(), v.end(), 1); // natürliche Zahlen 1 bis 10
    partial_sum(v.begin(), v.end(), partialsummen.begin());
    cout << "Partialsummen    = ";
    showSequence(partialsummen);         // 1 3 6 10 15 21 28 36 45 55
    cout << "Folge von Fakuläten  = "; 
    partial_sum(v.begin(), v.end(), v.begin(), multiplies<long>());
    showSequence(v); // 1 2 6 24 120 720 5040 40320 362880 3628800
}
