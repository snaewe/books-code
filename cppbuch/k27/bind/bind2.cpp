/* cppbuch/k27/bind/bind2.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<vector>
#include<iostream>
#include<algorithm>
#include<functional>
using std::bind; 
using namespace std::placeholders;

int main() {
   std::vector<int> v;
   v.push_back(111);
   v.push_back(107);
   v.push_back(101);
   v.push_back(90);
   v.push_back(106);

   int wert = 103;
   std::cout << "Das erste Element < " << wert << " ist: " <<
      *find_if(v.begin(), v.end(), 
               bind(std::less<int>(), _1, wert))   << std::endl;

}
