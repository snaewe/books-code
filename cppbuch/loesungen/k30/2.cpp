/* cppbuch/loesungen/k30/2.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<map>
#include<algorithm>
#include"rangvergleich.h"
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

   // nur der Rang interessiert, siehe rangvergleich.h
   pair<int, string> gesuchtesPaar(8, "Dummy");
   cout << "Es gibt folgende Einträge mit Rang " 
        << gesuchtesPaar.first << ":" << endl;

   pair<multimap<int, string, greater<int> >::iterator,
        multimap<int, string, greater<int> >::iterator> 
    bereich = equal_range(promis.begin(), promis.end(), 
                          gesuchtesPaar, Rangvergleich());

   for(multimap<int, string>::iterator iter = bereich.first;
           iter != bereich.second; ++iter) {
      cout << (*iter).second << endl;
   }
}
