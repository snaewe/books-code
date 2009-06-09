/* cppbuch/k24/vermischtes/copy/copy_if.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#if  __GNUC__*10+__GNUC_MINOR__ < 44 
#error Die Uebersetzung dieses Programms verlangt mindestens G++ 4.4
#else
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<showSequence.h>
#include<functional>
using std::bind;
using namespace std::placeholders;
using namespace std;


int main() {
   typedef vector<int> Container;
   Container container1(20);
   iota(container1.begin(), container1.end(), 1);
   showSequence(container1);
   Container container2;   // leeren Container anlegen
   // alle Elemente > 10 am Ende einfügen:
   copy_if(container1.begin(), container1.end(),
           back_inserter(container2),
           bind(greater<int>(), _1, 10));
   showSequence(container2);
}
#endif
