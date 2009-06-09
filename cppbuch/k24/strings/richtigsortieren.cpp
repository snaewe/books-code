/* cppbuch/k24/strings/richtigsortieren.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<iostream>
#include<vector>
#include<showSequence.h>
using namespace std;

int main() {
   vector<string> v;
   v.push_back("ähnlich");
   v.push_back("alphabet");
   v.push_back("Ähnlich");
   v.push_back("Alphabet");
   v.push_back("aal");
   v.push_back("Aal");
   v.push_back("Süße");
   v.push_back("Süsse");
   cout << "vorher:";
   showSequence(v);
   sort(v.begin(), v.end());
   cout << "nach Sortieren ohne Compare-Objekt:\n";
   showSequence(v);
   locale deutsch("de_DE");
   sort(v.begin(), v.end(), deutsch);
   cout << "nach Sortieren (locale de_DE):\n";
   showSequence(v);
}

