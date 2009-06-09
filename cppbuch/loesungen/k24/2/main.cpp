/* cppbuch/loesungen/k24/2/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include"heap.t"
using namespace std;

int main() {
   Heap<pair<int, string> > promis;
   promis.push(make_pair(7, "Jack Nicholson"));
   promis.push(make_pair(10, "Bill Clinton"));
   promis.push(make_pair(7, "Thomas Gottschalk"));
   promis.push(make_pair(8, "Brad Pitt"));
   promis.push(make_pair(8, "Peter Jackson"));
   promis.push(pair<int, string>(10, "Tina Turner"));

   cout << "Sortiert:" << endl;
   vector<pair<int, string> > vs = promis.toSortedVector();
   for(size_t i=0; i < vs.size(); ++i) {
      cout << vs[i].second << ", Priorität "
           << vs[i].first  << endl;
   }

   cout << "Leeren:" << endl;
   while(!promis.empty()) {
      cout << promis.top().second << ", Rang "
           << promis.top().first 
           << " size=" << promis.size()
           << endl;
      promis.pop();
   }
}
