/* cppbuch/loesungen/k5/5.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
// Die Funktion entspricht der Funktion strcpy() der C++-Standardbibliothek.
#include<iostream>
#include<cassert>
#include<cstring>
using std::cout;
using std::endl;

void strcopy(char *ziel, const char *quelle) {
// kopiert den Inhalt von quelle in den String ziel (und
// überschreibt den vorherigen Inhalt von ziel dabei).
     while((*ziel++ = *quelle++));
}

int main() {
      const char * const original = "Alles Gute!";
      cout << original << endl;
      char kopie[80];
      assert(sizeof kopie > strlen(original));
      strcopy(kopie, original);
      cout << kopie << endl;
}
