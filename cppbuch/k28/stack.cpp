/* cppbuch/k28/stack.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<stack> 
#include<iostream>
using namespace std;

int main() {
    int numbers[] = {1, 5, 6, 0, 9, 1, 8, 7, 2};
    const int COUNT = sizeof(numbers)/sizeof(int);
    stack<int> einStack;
    cout << "Zahlen auf dem Stack ablegen:" << endl;
    for(int i = 0; i < COUNT; ++i) {
         cout.width(6); cout << numbers[i];
         einStack.push(numbers[i]);
    }
    cout << endl;
    cout << "Zahlen vom Stack holen (umgekehrte Reihenfolge!),"
       " anzeigen und löschen:" << endl;
    while(!einStack.empty()) {
         cout.width(6); 
         cout << einStack.top(); // obersten Wert anzeigen
         einStack.pop();         // Wert löschen
    }  
    cout << endl;
}
