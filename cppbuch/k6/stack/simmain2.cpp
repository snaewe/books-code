/* cppbuch/k6/stack/simmain2.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
// Anwendungsbeispiele für Stack-Template
#include<iostream>
#include"simstack2.t"
using namespace std;

int main() {
    // ein Stack für 100 int-Zahlen
    SimpleStack<int,100> einIntStack; 

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

}
