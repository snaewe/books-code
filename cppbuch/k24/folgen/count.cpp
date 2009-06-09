/* cppbuch/k24/folgen/count.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<vector>
#include<showSequence.h>
#include<Random.h>
using namespace std;

bool ungerade(int zahl) {
   return zahl % 2 != 0;
}

int main() {
   vector<int> v;
   Random zufall;
   for(size_t i = 0; i < 20; ++i) {
      v.push_back(zufall(1000));
   }
   showSequence(v); 
   int gesucht = 277;
   cout << "Es sind " 
        << count(v.begin(), v.end(), gesucht)
        << " Elemente mit dem Wert " << gesucht << " vorhanden."
        << endl;

   cout << "Es sind " 
        << count_if(v.begin(), v.end(), ungerade)
        << " ungerade Elemente vorhanden."  << endl;
}
