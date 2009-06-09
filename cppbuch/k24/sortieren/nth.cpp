/* cppbuch/k24/sortieren/nth.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<deque>
#include<functional>
#include<showSequence.h>
#include<Random.h>
using namespace std;

int main() {
    deque<int> d;
    Random zufall;
    for(size_t i = 0; i < 15; ++i) {
       d.push_front(zufall(100));
    }
    showSequence(d); // 95 51 36 62 47 55 27 76 33 19 91 79 78 39 84
    deque<int>::iterator nth = d.begin();
    nth_element(d.begin(), nth, d.end());
    cout << "Kleinstes Element: " << (*nth) << endl;             // 19


    // Das Standard-Vergleichsobjekt \tt{greater} dreht die Reihenfolge um.
    // In diesem Fall stejt das größte Objekt an der ersten Position.
    // Hier ist immer noch \tt{nth == d.begin()}.
    nth_element(d.begin(), nth, d.end(), greater<int>());
    cout << "Größstes Element : "  << (*nth) << endl;             // 95

    // Mit dem < -Operator steht das größte Element am Ende:
    nth = d.end();      
    --nth;              // zeigt nun auf das letzte Element
    nth_element(d.begin(), nth, d.end());
    cout << "Größtes Element  : "   << (*nth) << endl;            // 95

    // Median 
    nth = d.begin() + d.size()/2;
    nth_element(d.begin(), nth, d.end());   
    cout << "Medianwert       :"  << (*nth) << endl;              // 55
}
