/* cppbuch/loesungen/k5/6.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
// Die Funktion entspricht der Funktion strdup() der C++-Standardbibliothek.
#include<iostream>
#include<cstring>
using namespace std;

char* strduplikat(const char *s) {
// liefert einen Zeiger auf den neu erzeugten String.
    char* neu = new char[strlen(s)+1];
    strcpy(neu,s);  // wie strcopy() aus Aufgabe 5
    return neu;
}

int main() {
      const char * const original = "Alles Gute!";
      cout << original << endl;
      char *kopie = strduplikat(original);
      cout << kopie << endl;
      delete kopie;
}
