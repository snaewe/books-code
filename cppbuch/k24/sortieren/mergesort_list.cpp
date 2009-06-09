/* cppbuch/k24/sortieren/mergesort_list.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<list>
#include<showSequence.h>
#include"mergesort.t"
#include<Random.h>

using namespace std;

int main() {     // mit Liste statt Vektor
    list<int> liste;
    Random zufall;
    for(size_t i = 0; i < 20; ++i) {
       liste.push_front(zufall(1000));      // pseudo-zufällige Zahlen 
    }
    showSequence(liste);
    list<int> buffer = liste;
    mergesort(liste.begin(), liste.end(), buffer.begin());
    showSequence(liste);     // sortierte Zahlen
}
