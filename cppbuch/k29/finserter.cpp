/* cppbuch/k29/finserter.cpp
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
   while (first != last) {
        *result++ = *first++;
   }
    return result;
}

int main() {
    std::list<int> liste(5, 0);     // 5 Nullen

    std::cout << "liste.size() = "
              << liste.size() << std::endl;

    showSequence(liste);
    std::list<int> liste2;         // leer

    copyadd(liste.begin(), liste.end(), 
            std::front_inserter(liste2));


    std::cout << "liste2.size() = "
              << liste2.size() << std::endl;

    showSequence(liste2);
}
