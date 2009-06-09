/* cppbuch/loesungen/k30/1.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<map>
#include<algorithm>
#include"gleicherrang.h"
using namespace std;

int main() {
   multimap<int, string, greater<int> > promis;
   promis.insert(make_pair(7, "Jack Nicholson"));
   promis.insert(make_pair(10, "Bill Clinton"));
   promis.insert(make_pair(7, "Thomas Gottschalk"));
   promis.insert(make_pair(8, "Brad Pitt"));
   promis.insert(make_pair(8, "Peter Jackson"));
   promis.insert(pair<int, string>(10, "Tina Turner"));
   for(multimap<int, string>::iterator iter = promis.begin();
       iter != promis.end(); ++iter) {
      cout << (*iter).second << ", Priorität "
           << (*iter).first << endl;
   }
   int gesucht = 8;
   cout << "Es gibt "
        << count_if(promis.begin(), promis.end(), GleicherRang(gesucht))
        << " Einträge mit Rang " << gesucht << endl;
}
