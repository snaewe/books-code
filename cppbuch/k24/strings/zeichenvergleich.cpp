/* cppbuch/k24/strings/zeichenvergleich.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include"localeutils.t"
using namespace std;

int main() {
   locale::global(locale("de_DE")); // deDE global setzen
   string s1("ähnlich_x");
   string s2("ÄHNLICH_Y");
   for(size_t i = 0; i < s1.length() && i < s2.length(); ++i) {
         cout << "Die Zeichen Nr. " << i << " (" 
              << s1[i]<< ", " <<  s2[i] << ") werden als "; 
      if(!equalIgnoreCase(s1[i], s2[i])) { 
         cout << "un";
      }
      cout << "gleich gewertet." << endl;
   }
}

