/* cppbuch/k24/vermischtes/fill.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<vector>
#include<showSequence.h>
using namespace std;

int main() {
    vector<double> v(8);
    // alle Werte mit 9.23 initialisieren
    fill(v.begin(), v.end(), 9.23);

    showSequence(v);

    /* fill_n() erwartet die Anzahl der zu initialisierenden Elemente
       und gibt einen Iterator auf das Ende des Bereichs zurück.
       Hier wird nur die erste Hälfte der Sequenz auf 1.01 geändert.
    */
    vector<double>::const_iterator iter =
       fill_n(v.begin(), v.size()/2, 1.01);

    showSequence(v);
    cout << "Der Iterator befindet sich an Stelle "
         << (iter - v.begin())
         << ", *iter = " << *iter << endl;
}
