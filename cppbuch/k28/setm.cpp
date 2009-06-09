/* cppbuch/k28/setm.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<set>
#include"../include/showSequence.h"
using namespace std;

int main() {
   set<int> einSet;  //  vordefinierter Vergleich: less<int>()

    for(int i = 0; i < 10; ++i) einSet.insert(i);
    for(int i = 0; i < 10; ++i) einSet.insert(i); // keine Wirkung
    showSequence(einSet);                 // 0 1 2 3 4 5 6 7 8 9

    /* Die Ausgabe zeigt, dass die Elemente trotz zweifachen insert()-Aufrufs
nur einmal vorkommen. Im nächsten Teil wird ein Element gelöscht,
einmal über einen Iterator, und einmal über seinen Wert.*/

    cout << "Löschen mit Iterator\n"
            "Welches Element? (0..9)" ;
    int i;
    cin >> i;
    set<int>::const_iterator iter = einSet.find(i);
    if(iter == einSet.end()) {
       cout << i << " nicht gefunden!\n";
    }
    else {
        // count() kann nur 0 oder 1 ergeben.
        cout << "Das Element " << i            // 1
             << " existiert " << einSet.count(i) << " mal." << endl;
        einSet.erase(iter);
        cout << i << " gelöscht!\n";
        cout << "Das Element " << i            // 0
             << " existiert " << einSet.count(i) << " mal." << endl;
    }
    showSequence(einSet);

    cout << "Löschen durch Suche nach dem Wert\n"
            "Welches Element? (0..9)" ;
    cin >> i;
    int anzahl = einSet.erase(i);
    if(anzahl == 0) {
       cout << i << "  nicht gefunden!\n";
    }
    showSequence(einSet);

    cout << "Konstruktor mit Iterator-Bereich\n";

    // 2 und 1 zweimal!
    int tabelle[] = { 1, 2, 2, 3, 4, 9, 13, 1, 0, 5};
    anzahl = sizeof(tabelle)/sizeof(tabelle[0]);

    set<int> zahlenSet(tabelle, tabelle + anzahl);
    showSequence(zahlenSet);    // 0 1 2 3 4 5 9 13
}
