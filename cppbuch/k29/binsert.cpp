/* cppbuch/k29/binsert.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<showSequence.h>
#include<vector>
#include<iterator>
using namespace std;

int main() {
    vector<int> einVektor(5, 0);      // 5 zeros
    cout << "einVektor.size() = "
         << einVektor.size() << endl; // 5
    showSequence(einVektor);          // 0 0 0 0 0

    back_insert_iterator<vector<int> >
                      aBackInserter(einVektor);   

    // Einfügen mit den Operationen *, ++, =
    int i = 1;
    while(i < 3) {
          *aBackInserter++ = i++;
    }
    cout << "einVektor.size() = "
         << einVektor.size() << endl;  // 7

    showSequence(einVektor);           // 0 0 0 0 0 1 2
}

