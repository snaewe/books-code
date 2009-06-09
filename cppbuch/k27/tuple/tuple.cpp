/* cppbuch/k27/tuple/tuple.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#if  __GNUC__*10+__GNUC_MINOR__ < 44 
#error Die Uebersetzung dieses Programms verlangt mindestens G++ 4.4
#else
#include<iostream>
#include<string>
#include<tuple>

using namespace std;

int main() {
   tuple<string, string> t2("Donald", "Knuth");
   tuple<string, string, int> t3("Donald", "Duck", 17);
   cout << "Zugriff mit get<>: "
        << get<0>(t2) << " " << get<1>(t2) << endl;
      // get<>() gibt Referenzen zurück
   get<0>(t3) = "Dagobert";
   cout << get<0>(t3) << " " << get<1>(t3) << endl; 
   typedef tuple<string, string> tupeltyp;
   cout << "tupeltyp hat " 
        << tuple_size<tupeltyp>::value << " Elemente" << endl; 
}
#endif
