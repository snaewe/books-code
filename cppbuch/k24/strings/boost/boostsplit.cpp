/* cppbuch/k24/strings/boost/boostsplit.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<string>
#include<vector>
#include<boost/algorithm/string/split.hpp>
#include<boost/algorithm/string/classification.hpp>  // is_any_of
#include<showSequence.h>

using namespace std;
using namespace boost::algorithm;

int main() {
   string text("The quick brown fox jumps over the lazy dog's back.");
   vector<string> v;
   split(v, text, is_any_of(" ,."));
   showSequence(v, "", "*\n");
}

