/* cppbuch/k24/folgen/uniqueptr.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
#include<showSequence.h>
using namespace std;

void anzeige(const vector<string*>& v) {  // Hilfsfunktion
   for(size_t i = 0; i < v.size(); ++i) {
      cout << *v[i] << "  ";
   }
   cout << endl;
}

bool gleich(const string* p1, const string* p2) {
   return *p1 == *p2; // Vergleich der Werte, nicht der Zeiger
}

bool kleiner(const string* p1, const string* p2) {
   return *p1 < *p2; // Vergleich der Werte, nicht der Zeiger
}


int main() {
                     // automatische Typumwandlung in string
   string strarr[] = {"string", "array", "mit", "mit", "dubletten",
                      "dubletten","dubletten"}; 
   size_t anzahl =  sizeof(strarr)/sizeof(strarr[0]);
   vector<string*> v;
   for(size_t i = 0; i < anzahl; ++i) {
      v.push_back(&strarr[i]);
   }
   cout << "Original:\n";
   anzeige(v);
   // Voraussetzung: Container ist sortiert
   sort(v.begin(), v.end(), kleiner);
   cout << "sortiert:\n";
   anzeige(v);
   v.erase(unique(v.begin(), v.end(), gleich), v.end());
   cout << "nach erase:\n";
   anzeige(v);
}
