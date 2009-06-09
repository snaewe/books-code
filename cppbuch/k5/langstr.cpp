/* cppbuch/k5/langstr.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<cstring>
#include<iostream>
using namespace std;

int main() {
    const char* const TEXT= "Bei Initialisierung, Zuweisung, oder "
                "Ausgabe kann ein Stringliteral wie hier auch aus "
                "einzelnen Teilstrings zusammengesetzt werden.";
    cout << TEXT << endl
         << "enthält " << strlen(TEXT) << " Zeichen\n";
}
