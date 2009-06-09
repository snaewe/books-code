/* cppbuch/k31/narrow.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main() {
   locale loc;
   cout << "loc.name()= " << loc.name() << endl;
   locale dt("de_DE");
   cout << "dt.name()= " << dt.name() << endl;
   locale vorher = locale::global(dt); // dt für alles setzen

   string s("ÄÖÜäöüß");
   cout.imbue(dt);
   for(size_t i = 0; i < s.length(); ++i) {
      cout << "Zeichen " << i << ": "  // = byte
           << s[i] << "   " << ((int)s[i] +256) << endl; 
   }
   for(size_t i = 0; i < s.length(); ++i) {
      cout << toupper(s[i], dt)  << tolower(s[i], dt) << " ";
   }
   for(size_t i = 0; i < s.length(); ++i) {
      s[i] =toupper(s[i], dt); 
   }
   cout << "\n Nach toupper: " << s  << endl;  
   // Andere Möglichkeit, jetzt mit tolower:
   use_facet<ctype<char> >(dt).tolower(&s[0], s.c_str() + s.length());
   cout << "\n Nach tolower: " << s << endl;  
}

/*
ISO 8859-1: Bits 0-127 wie ASCII
reicht für sehr viele Sprachen aus, hat aber kein Euro- Symbol
Ae  196 0xC4
Oe  214 0xD6
Ue  220 0xDC
ae  228 0xE4
oe  246 0xF6
ue  252 0xFC
sz  223 0xDF
Euro ist 164 0xA4 bei ISO 8859-15 

*/
