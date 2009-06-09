/* cppbuch/k24/strings/stringvergleich.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include"localeutils.t"
using namespace std;

int main() {
   locale::global(locale("de_DE")); // deDE global setzen
   Stringvergleich<char> sv;
   string s1("ähnlich");
   string s2("bildschön");
   if(sv(s1, s2)) {
      cout << s1 << " kommt vor " << s2 << endl;
   }
   else {
      cout << s2 << " kommt vor " << s1 << endl;
   }
}

