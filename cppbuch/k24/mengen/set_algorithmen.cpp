/* cppbuch/k24/mengen/set_algorithmen.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
// cppbuch/k18/set_algorithms.cpp
#include<algorithm>
#include<set>
#include<showSequence.h>
using namespace std;

int main () {
    int v1[] = {1, 2, 3, 4};
    int v2[] = {0, 1, 2, 3, 4, 5, 7, 99, 13};
    int v3[] = {-2, 5, 12, 7, 33};

    /*  Sets mit den Vektorinhalten initialisieren. 
        Vergleichsobjekt: less<int>()
        (implizite automatische Sortierung).
       sizeof v/sizeof *v1 = Anzahl der Elemente in v
    */   
    set<int> s1(v1, v1 + sizeof v1/sizeof *v1);
    set<int> s2(v2, v2 + sizeof v2/sizeof *v2);
    set<int> s3(v3, v3 + sizeof v3/sizeof *v3);

    if(includes(s2.begin(), s2.end(), s1.begin(), s1.end())) {
        showSequence(s1);              // 1 2 3 4
        cout << " ist eine Teilmenge von ";
        showSequence(s2);              // 0 1 2 3 4 5 7 99
    }

    set<int> result;          // leere Menge (s1, s2, s3 wie oben)
    set_union(s1.begin(), s1.end(),
              s3.begin(), s3.end(),
              inserter(result, result.begin()));      

    showSequence(s1);                  // 1 2 3 4
    cout << " vereinigt mit ";
    showSequence(s3);                  // -2 5 7 12 33
    cout << " ergibt ";
    showSequence(result);            // -2 1 2 3 4 5 7 12 33

    result.clear();                  // Set leeren
    set_intersection(s2.begin(), s2.end(),
                     s3.begin(), s3.end(),
                     inserter(result, result.begin()));

    showSequence(s2);                  // 0 1 2 3 4 5 7 99
    cout << " geschnitten mit ";
    showSequence(s3);                  // -2 5 7 12 33
    cout << " ergibt ";
    showSequence(result);            // 5 7

    result.clear();
    set_difference(s2.begin(), s2.end(),
                   s1.begin(), s1.end(),
                   inserter(result, result.begin()));

    showSequence(s2);                  // 0 1 2 3 4 5 7 99
    cout << " minus ";
    showSequence(s1);                  // 1 2 3 4
    cout << " ergibt ";
    showSequence(result);              // 0 5 7 99

    result.clear();
    set_symmetric_difference(s2.begin(), s2.end(),
                             s3.begin(), s3.end(),
                 inserter(result, result.begin()));

    showSequence(s2);                  // 0 1 2 3 4 5 7 99
    cout << "  exklusiv oder ";
    showSequence(s3);                  // -2 5 7 12 33
    cout << " ergibt ";
    showSequence(result);              // -2 0 1 2 3 4 12 33 99
}

