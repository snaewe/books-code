/* cppbuch/k28/list/splice.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<list>
#include<iostream>
using namespace std;

void displayIntList(const list<int> & L)  { // auxiliary function
    list<int>::const_iterator I = L.begin();
    while(I != L.end())
         cout << *I++ << ' ';
    cout << " size() ="
              << L.size() << endl;
}

int main( ) {
    list<int> L1, L2;

    // fill lists with sorted numbers
    for(int i = 0; i < 10; ++i) {
        L1.push_back(2*i);       // even numbers
        L2.push_back(2*i+1);     // odd numbers
    }
    displayIntList(L1); // 0 2 4 6 8 10 12 14 16 18  size() =10
    displayIntList(L2); // 1 3 5 7 9 11 13 15 17 19  size() =10

    list<int>::iterator I = L2.begin();
    advance(I, 4);                         // 4 steps
    L1.splice(L1.begin(), L2, I, L2.end());
    cout << " after splicing L1 and L2:\n";
    displayIntList(L1); // 9 11 13 15 17 19 0 2 4 6 8 10 12 14 16 18  size() =16         

    displayIntList(L2); // 1 3 5 7  size() =4 
}


