/* cppbuch/k29/insert.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<showSequence.h>
#include<vector>
#include<iterator>

int main() {
    std::vector<int> einVektor(5, 0);      // 5 Nullen

    std::cout << "einVektor.size() = "
         << einVektor.size() << std::endl;  //  5
    showSequence(einVektor);   //  0 0 0 0 0


    // Einfügen mit den Operationen *, ++, =
    std::insert_iterator<std::vector<int> >
        aBeginInserter(einVektor, einVektor.begin());

    int i = 1;
    while(i < 3) 
         *aBeginInserter++ = i++;
    // vector:  1 2 0 0 0 0 0
    // size() ist jetzt 7

    std::insert_iterator<std::vector<int> >
        aMiddleInserter(einVektor, einVektor.begin() +
                         einVektor.size()/2);

    while(i < 6)
       *aMiddleInserter++   = i++;
    // vector:  1 2 0 3 4 5 0 0 0 0
    // size() ist jetzt 10

    std::insert_iterator<std::vector<int> >
        anEndInserter(einVektor, einVektor.end());
    while(i < 9) 
         *anEndInserter++    = i++;

    std::cout << "einVektor.size() = "
         << einVektor.size() << std::endl;  //  13
    showSequence(einVektor);   //  1 2 0 3 4 5 0 0 0 0 6 7 8
}
