/* cppbuch/k6/stack/simmain1.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
// Anwendungsbeispiele für Stack-Template
#include<iostream>
#include"simstack1.t"
using namespace std;

int main() {
    SimpleStack<int> einIntStack;  // ein Stack für int-Zahlen

    // Stack füllen
    int i = 100;
    while(!einIntStack.full())
          einIntStack.push(i++);
    cout << "Anzahl : " << einIntStack.size() << endl;

    // oberstes Element anzeigen
    cout << "oberstes Element: "
         << einIntStack.top() << endl;

    cout << "alle Elemente entnehmen und anzeigen: " << endl;
    while(!einIntStack.empty()) {
        i = einIntStack.top();
        einIntStack.pop();
        cout << i << '\t';
    }
    cout << endl;

    // ein Stack für double-Zahlen
    SimpleStack<double> einDoubleStack;

    // Stack mit (beliebigen) Werten füllen
    double d = 1.00234;
    while(!einDoubleStack.full()) {
         d = 1.1 * d;
         einDoubleStack.push(d);
         cout << einDoubleStack.top() << '\t';
    }

    // einDoubleStack.push(1099.986);  // Fehler, da Stack voll

    cout << "\n4 Elemente des Double-Stacks entnehmen:" << endl;
    for (i = 0; i < 4; ++i) {
        cout << einDoubleStack.top() << '\t';
        einDoubleStack.pop();
    }
    cout << endl;

    cout << "Restliche Anzahl : "
         << einDoubleStack.size() << endl;

    cout << "clear Stack" << endl;
    einDoubleStack.clear();
    cout << "Anzahl : " << einDoubleStack.size() << endl;

   //  einDoubleStack.pop();  // Fehler, da Stack leer
}
