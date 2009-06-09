/* cppbuch/k28/vector/intvec.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<vector>
#include<iostream>
#include<cstddef>
using namespace std;

int main() {
    // int-Vektor mit 10 Elementen
    vector<int> intV(10);

    for(size_t i = 0; i < intV.size(); ++i)
       intV[i] = i;                 // Vektor füllen

    // Vektor wächst dynamisch
    intV.insert(intV.end(), 100);   //  100 anhängen

    // Benutzung wie Array
    for(size_t i = 0; i < intV.size(); ++i)
       cout << intV[i] << endl;

    // Benutzung mit Iterator
    for(vector<int>::const_iterator I = intV.begin(); 
                                     I != intV.end(); ++I)
       cout << *I << endl;
    
    vector<int> newV(20, 0); // alle Elemente nullen
    
    cout << " newV = ";

    for(size_t i = 0; i < newV.size(); ++i)
       cout << newV[i] << ' ';

    // swap() ist eine schnelle Methode zur Vertauschung
    // zweier Vektoren
    newV.swap(intV);

    cout << "\n newV nach swap() = ";
    for(size_t i = 0; i < newV.size(); ++i)
       cout << newV[i] << ' ';     // alter Inhalt von  intV

    cout << "\n\n intV        = ";
    for(size_t i = 0; i < intV.size(); ++i)
       cout << intV[i] << ' ';     //  alter Inhalt von  newV
    cout << endl;
}
