/* cppbuch/k24/sortieren/merge0.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<vector>
#include<numeric>
#include<showSequence.h>
#if  __GNUC__*10+__GNUC_MINOR__ < 44 
#include<ersatziota.h>
#endif
using namespace std;

int main() {
    vector<int> folge1(6); 
    iota(folge1.begin(), folge1.end(), 0);   // initialisieren
    showSequence(folge1);                
    vector<int> folge2(10);
    iota(folge2.begin(), folge2.end(), 0);   // initialisieren
    showSequence(folge2);                
    vector<int> result(folge1.size()+folge2.size());
    // Verschmelzen zweier Folgen \tt{v1} und \tt{v2}, Ablage in \tt{result}
    merge(folge1.begin(), folge1.end(), folge2.begin(), folge2.end(), result.begin());
    showSequence(result);
}
