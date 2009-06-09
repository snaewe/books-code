/* cppbuch/k29/finsert.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<showSequence.h>
#include<list>
#include<iterator>

int main() {
   std::list<int> aList(5, 0);     // 5 Nullen

   std::cout << "aList.size() = "
             << aList.size() << std::endl;

   showSequence(aList);

   std::front_insert_iterator<std::list<int> >
      aFrontInserter(aList);

   // Einfügen mit den Operationen *, ++, =
   int i = 1;
   while(i < 3) {
      *aFrontInserter++ = i++;
   }

   std::cout << "aList.size() = "
             << aList.size() << std::endl;

   showSequence(aList);
}
