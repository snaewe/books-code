/* cppbuch/k24/finden/search.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<vector>
#include<iostream>
#include<cstdlib>
#include<showSequence.h>

class Absolutvergleich { //  Vorzeichen ignorieren
    public:
      bool operator()(int x, int  y) {
          return abs(x) == abs(y);
      }
};

using namespace std;

int main() {
    vector<int> folge(12);
    for(size_t i = 0; i < folge.size(); ++i) {
        folge[i] = i;        // 0 1 2 3 4 5 6 7 8 9 10 11
    }
    cout << "Folge = ";
    showSequence(folge);

    vector<int> teilfolge(4);
    for(size_t i = 0; i < teilfolge.size(); ++i)
        teilfolge[i] = i + 5;    // 5 6 7 8
    cout << "Teilfolge = ";
    showSequence(teilfolge);

    // Teilfolge in Folge suchen
    vector<int>::const_iterator position = search(folge.begin(), folge.end(),
                       teilfolge.begin(), teilfolge.end());
    if(position != folge.end()) {
        cout << " Die Teilfolge ist in der Folge ab Position "
                  << (position - folge.begin())
                  << " enthalten." << endl;
    }
    else {
        cout << "Die Teilfolge ist nicht in der Folge enthalten." << endl;
    }
    // Fall2: binäres Prädikat. Dafür negative Zahlen setzen
    for(size_t i = 0; i < teilfolge.size(); ++i) {
        teilfolge[i] = -(i + 5); // -5 -6 -7 -8
    }
    cout << "Teilfolge = ";
    showSequence(teilfolge);

    // Teilfolge in Folge suchen, dabei Vorzeichen ignorieren
    position = search(folge.begin(), folge.end(),
                       teilfolge.begin(), teilfolge.end(),
                       Absolutvergleich());
    if(position != folge.end()) {
        cout << " Die Teilfolge ist in der Folge ab Position "
                  << (position - folge.begin())
                  << " enthalten. Vorzeichen wurden ignoriert" << endl;
    }
    else {
        cout << "Die Teilfolge ist nicht in der Folge enthalten." << endl;
    }
}
