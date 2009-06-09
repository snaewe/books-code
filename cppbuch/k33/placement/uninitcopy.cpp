/* cppbuch/k33/placement/uninitcopy.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<iostream>
#include<new>
#include<vector>
#include<showSequence.h>

using namespace std;

int main() {
   vector<int> v1(10), v2(10);
   fill(v1.begin(), v1.end(), 999);  // v1 mit Daten füllen
   // v1 nach v2 kopieren:
   uninitialized_copy(v1.begin(), v1.end(),v2.begin());
   showSequence(v2);
}
