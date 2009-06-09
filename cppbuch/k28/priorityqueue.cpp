/* cppbuch/k28/priorityqueue.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<queue> 
#include<vector>
#include<iostream>
using namespace std;

int main() {
    int numbers[] = {1, 5, 6, 0, 9, 1, 8, 7, 2};
    const int COUNT = sizeof(numbers)/sizeof(int);

    // Standard-Implementierung mit deque und less
    priority_queue<int> einePrioQueue;
    // ALTERNATIV
    // Implementierung der priority_queue mit vector
    // priority_queue<int, vector<int>, greater<int> > einePrioQueue;
    // greater: kleine Elemente zuerst (= hohe Priorit‰t)
    // less:  groﬂe Elemente zuerst
    cout << "Zahlen in die Priorit‰ts-Warteschlange schreiben:" << endl;
    for(int i = 0; i < COUNT; ++i) {
         cout.width(6); cout << numbers[i];
         einePrioQueue.push(numbers[i]);
    }

    cout << "\nZahlen aus der Priorit‰ts-Warteschlange holen,"
          " anzeigen und lˆschen:" << endl;
    while(!einePrioQueue.empty()) {
         cout.width(6); 
         cout << einePrioQueue.top();       // 'wichtigsten' Wert anzeigen
         einePrioQueue.pop();                // Wert lˆschen
    }  
    cout << endl;
}
