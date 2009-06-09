/* cppbuch/loesungen/k28/2.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<utility>
#include<queue>
#include<string>
using namespace std;

int main() {
   priority_queue<pair<int, string> > promis;
   promis.push(make_pair(7, "Jack Nicholson"));
   promis.push(make_pair(10, "Bill Clinton"));
   promis.push(make_pair(7, "Thomas Gottschalk"));
   promis.push(make_pair(8, "Brad Pitt"));
   promis.push(make_pair(8, "Peter Jackson"));
   promis.push(pair<int, string>(10, "Tina Turner"));
   while(!promis.empty()) {
      cout << promis.top().second << ", Priorität "
           << promis.top().first << endl;
      promis.pop();
   }
}
