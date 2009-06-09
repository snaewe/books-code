/* cppbuch/k24/folgen/rshuffle.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<vector>
#include<numeric>
#include<showSequence.h>
#include<Random.h>
#if  __GNUC__*10+__GNUC_MINOR__ < 44 
#include<ersatziota.h>
#endif
using namespace std;

int main() {
    vector<int> v(12);
    iota(v.begin(), v.end(), 0);   // 0 1 2 3 4 5 6 7 8 9 10 11
    
    // Benutzung des internen Zufallszahlengenerators
    random_shuffle(v.begin(), v.end());
    showSequence(v);
    
    // Benutzung eines eigenen Zufallszahlengenerators
    Random zufall;
    random_shuffle(v.begin(), v.end(), zufall);
    showSequence(v);

}
