/* cppbuch/k29/binserter.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<showSequence.h>
#include<vector>
#include<iterator>

template <class InputIterator, class OutputIterator>
OutputIterator copyadd(InputIterator first,
                       InputIterator last,
                       OutputIterator result) {
    while (first != last) 
        *result++ = *first++;
    return result;
}

int main() {
    std::vector<int> aVector(5, 0);      // 5 Nullen
    std::cout << "aVector.size() = "
         << aVector.size() << std::endl; // 5
    showSequence(aVector);          // 0 0 0 0 0

   // kopieren mit der Funktion back_inserter()
    std::vector<int> aVector2;            // Größe 0
    copyadd(aVector.begin(), aVector.end(),
                             std::back_inserter(aVector2));
    std::cout << "aVector2.size() = "
              << aVector2.size() << std::endl; //  7
    showSequence(aVector2);          
}

