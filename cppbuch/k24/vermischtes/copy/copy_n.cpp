/* cppbuch/k24/vermischtes/copy/copy_n.cpp
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

using namespace std;

int main() {
    vector<int> v1(20);
   iota(v1.begin(), v1.end(), 1);
   showSequence(v1);
   vector<int> v2(20, 0); 
   // die ersten 10 Elemente kopieren
   copy_n(v1.begin(), 10, v2.begin());
   showSequence(v2);
}
#endif
