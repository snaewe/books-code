/* cppbuch/k24/strings/split.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<string>
#include<vector>
#include<showSequence.h>


void split(const std::string& s, const std::string& trenn, 
           std::vector<std::string>& v) {
   size_t start = 0;
   size_t pos;
   do {
      pos = s.find_first_of(trenn, start);
      v.push_back(s.substr(start, pos-start));
      start = pos+1;
   } while(pos != std::string::npos);
}

using namespace std;

int main() {
   string text("The quick brown fox jumps over the lazy dog's back.");
   vector<string> v;
   split(text, " ,.", v);
   showSequence(v, "", "*\n");
}

