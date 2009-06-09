/* cppbuch/k27/pair/pairTR1.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
// Dasselbe wie pair.cpp, aber mit get<>() anstatt first bzw. second
#include<iostream>
#if  __GNUC__*10+__GNUC_MINOR__ < 44 
#include <tr1/utility>
using namespace std::tr1;
#else
#include <utility>
#endif
using namespace std;

int main() {
   pair<string, string> p1 = make_pair("Donald", "Knuth");
   pair<string, string> p2 = make_pair("Donald", "Duck");

   cout << "Vergleich zweier Paare" << endl;
   if(p1 > p2) {  // Anwendung von Operator >
      cout << get<0>(p2) << " " << get<1>(p2) 
           << " liegt alphabetisch vor "
           << get<0>(p1) << " " << get<1>(p1) << endl;
   } 
   else {
      cout << get<0>(p1) << " " << get<1>(p1) 
           << " liegt alphabetisch vor "
           << get<0>(p2) << " " << get<1>(p2) << endl;
   }
}
