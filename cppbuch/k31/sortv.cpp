/* cppbuch/k31/sortv.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<string>
#include<locale>
#include<vector>
#include<showSequence.h>
using namespace std;

int main() {
   locale dt("de_DE");
   cout << "dt.name()= " << dt.name() << endl;
   locale::global(dt); // dt für alles setzen, Rückgabewert ignorieren
   vector<string> v;
   v.push_back("Mucke");
   v.push_back("Mücke"); 
   v.push_back("Macke");
   v.push_back("Murks");
   sort(v.begin(), v.end());     // falsch  : Macke Mucke Murks Mücke
   showSequence(v);
   sort(v.begin(), v.end(), dt);  // korrekt: Macke Mucke Mücke Murks
   showSequence(v);
}
