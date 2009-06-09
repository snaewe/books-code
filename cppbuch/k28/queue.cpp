/* cppbuch/k28/queue.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<queue> 
#include<iostream>
using namespace std;

int main() {
    int numbers[] = {1, 5, 6, 0, 9, 1, 8, 7, 2};
    const int COUNT = sizeof(numbers)/sizeof(int);
    queue<int> eineQueue;
    cout << "Zahlen in die Warteschlange schreiben:" << endl;
    for(int i = 0; i < COUNT; ++i) {
         cout.width(6); cout << numbers[i];
         eineQueue.push(numbers[i]);
    }
    cout << "\n\nZahlen aus der Warteschlange holen, "
       "anzeigen und löschen:" << endl;
    while(!eineQueue.empty()) {
         cout.width(6); 
         cout << eineQueue.front();      // ersten Wert anzeigen
         eineQueue.pop();                // Wert löschen
    }  
    cout << endl;
}
