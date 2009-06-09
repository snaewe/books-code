/* cppbuch/k1/limits.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include <iostream>
#include<climits>           // hier sind die Bereichsinformationen
using namespace std;

int main() {
   cout << "Grenzwerte für Ganzzahl-Typen:" 
        << endl;  // = neue Zeile (endline)
   cout << "INT_MIN =       " << INT_MIN << endl;
   cout << "INT_MAX =       " << INT_MAX << endl;
   cout << "LONG_MIN =      " << LONG_MIN << endl;
   cout << "LONG_MAX =      " << LONG_MAX << endl;
   cout << "LLONG_MIN =     " << LLONG_MIN << endl;   // C++0x
   cout << "LLONG_MAX =     " << LLONG_MAX << endl;   // C++0x
   cout << "unsigned-Grenzwerte:" << endl;
   cout << "UINT_MAX =      " << UINT_MAX << endl;
   cout << "ULONG_MAX =     " << ULONG_MAX << endl;
   cout << "ULLONG_MAX =    " << ULLONG_MAX << endl;  // C++0x
   cout << "Anzahl der Bytes für:" << endl;
   cout << "int       " << sizeof(int) << endl;
   cout << "long      " << sizeof(long) << endl;
   cout << "long long " << sizeof(long long) << endl; // C++0x
}
