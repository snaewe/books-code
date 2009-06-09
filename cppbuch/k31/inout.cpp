/* cppbuch/k31/inout.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <locale>
using namespace std;

int main() {
  cin.imbue(locale("de_DE"));
  cout.imbue(locale("en_US"));
  double f;
  while (cin >> f)       // implizite Nutzung von \tt{num\_get}
    cout << f << endl;   // implizite Nutzung von \tt{num\_put}
}
