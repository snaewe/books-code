/* cppbuch/k24/heap/heap.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<showSequence.h>
#include<vector>
#include<numeric>
#if  __GNUC__*10+__GNUC_MINOR__ < 44 
#include<ersatziota.h>
#endif
using namespace std;

int main() {
    vector<int> v(12);           // Container für Heap
    iota(v.begin(), v.end(), 0); // 0 .. 11 einfügen
    showSequence(v); // 0 1 2 3 4 5 6 7 8 9 10 11

    // gültigen Heap erzeugen
    make_heap(v.begin(), v.end());
    showSequence(v); // 11 10 6 8 9 5 0 7 3 1 4 2
    // Die beiden Zahlen der höchsten Priorität anzeigen und entfernen:
    vector<int>::iterator last = v.end();
    cout << *v.begin() << endl;            // 11
    pop_heap(v.begin(), last--);

    cout << *v.begin() << endl;            // 10
    pop_heap(v.begin(), last--);

    /* Das Ende des Heaps wird nicht mehr durch v.end() markiert, sondern
       durch den Iterator last. Bezüglich der Heap-Eigenschaften von v
       ist der Bereich dazwischen undefiniert. */

    // 'wichtige' Zahl einfügen (99)
    *last = 99;
    push_heap(v.begin(), ++last);


    // 'unwichtige' Zahl einfügen (-1)
    *last = -1;
    push_heap(v.begin(), ++last);

    // Anzeige des vollständigen Heaps
    // (keine vollständige Sortierung, nur Heap-Bedingung!)
    showSequence(v);   
    // Anzeige aller Zahlen nach Priorität
    while(last != v.begin()) {
       cout << *v.begin() << ' ';
       pop_heap(v.begin(), last--);
    }
    cout << endl;      
    // neuen gültigen Heap erzeugen
    make_heap(v.begin(), v.end());                  

    // und sortieren
    sort_heap(v.begin(), v.end());
    // Anzeigen der vollständig sortierten Folge
    showSequence(v);   
}
