/* cppbuch/k24/sortieren/sort.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<vector>
#include<showSequence.h>
#include<Random.h>

using namespace std;

bool intVergleich(double x, double y) {   
   return long(x) < long(y);
}

int main() {
    vector<double> v(17);
    Random zufall;
    // Vektor mit Zufallswerten initialisieren. Dabei sollen einige Werte denselben
    // ganzzahligen Anteil haben, um den Unterschies von stabiler und nicht-stabiler
    // Sortierung sehen zu können.
    for(size_t i = 0; i < v.size(); ++i) {
       v[i] =  zufall(v.size()/3)
               + double(zufall(1000)/1000.0);
    }
    vector<double> unstable = v,       // Hilfsvektoren
                     stable = v;
    cout << "Vektor             :\n";
    showSequence(v);

    // Sortierung mit < Operator:
    stable_sort(stable.begin(), stable.end());
    cout << "Kein Unterschied, weil double-Zahlen als Key genommen werden\n"
            "stabile Sortierung   :\n";
    showSequence(stable);

    sort(unstable.begin(), unstable.end());
    cout << "unstabile Sortierung :\n";
    showSequence(unstable);

    //  Sortierung mit Funktion statt <
    unstable = v;
    stable = v;
    cout << "Unterschied, weil nur der int-Teil Sortierkriterium ist\n";

    stable_sort(stable.begin(), stable.end(),intVergleich);
    cout << "stabile Sortierung (int-Kriterium)  :\n";
    showSequence(stable);

    sort(unstable.begin(), unstable.end(), intVergleich);
    cout << "unstabile Sortierung (int-Kriterium)  :\n";
    showSequence(unstable);
}
