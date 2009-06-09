/* cppbuch/k29/inserter.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<showSequence.h>
#include<list>
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
    std::list<int> aList(5, 0);     // 5 Nullen

    std::cout << "aList.size() = "
              << aList.size() << std::endl;

    showSequence(aList);
    std::list<int> aList2;         // leer

    copyadd(aList.begin(), aList.end(), 
            std::inserter(aList2, aList2.begin()));

    std::cout << "aList2.size() = "
              << aList2.size() << std::endl;

    showSequence(aList2);
}
