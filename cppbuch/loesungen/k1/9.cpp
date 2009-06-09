/* cppbuch/loesungen/k1/9.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
using namespace std;

int main() {
    char c;
    bool zuEnde = false;
    while(!zuEnde) {
        cout << "Wählen Sie: a, b, x = Ende : ";
        cin >> c;

        switch(c) {
           case 'a': cout << "Programm a\n"; break;
           case 'b': cout << "Programm b\n"; break;
           case 'x': zuEnde = true;          break;
           default : cout << "Falsche Eingabe! "
                             "Bitte wiederholen!\n";
        }
    }
    cout << "\n Programmende\n";
}
