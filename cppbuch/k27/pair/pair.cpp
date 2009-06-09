/* cppbuch/k27/pair/pair.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include <utility>
#include<iostream>
using namespace std;

int main() {
   pair<string, string> p1 = make_pair("Donald", "Knuth");
   pair<string, string> p2 = make_pair("Donald", "Duck");

   cout << "Vergleich zweier Paare" << endl;
   if(p1 > p2) {  // Anwendung von Operator >
      cout << p2.first << " " << p2.second 
           << " liegt alphabetisch vor "
           << p1.first << " " << p1.second << endl;
   } 
   else {
      cout << p1.first << " " << p1.second 
           << " liegt alphabetisch vor "
           << p2.first << " " << p2.second << endl;
   }
}
