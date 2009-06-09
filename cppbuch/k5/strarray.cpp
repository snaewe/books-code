/* cppbuch/k5/strarray.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
// Beispiele für Zugriff auf String-Array
#include<iostream>
using namespace std;

int main() {
   const char* sa[] = {"eins\n", "zwei\n"};
   const char** sp = sa; // Zeiger auf const char*
                           // Programmausgabe:
   cout << sa[0]    << endl;    // eins
   cout << *sa      << endl;    // eins
   cout << sa[1]    << endl;    // zwei
   cout << sa[1][0] << endl;    // z
   cout << *sp      << endl;    // eins
   cout << sp[1]    << endl;    // zwei
}
