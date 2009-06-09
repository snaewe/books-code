/* cppbuch/k28/emplace/vec.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<vector>

class A {
public:
   A(int i, int j) : i_(i), j_(j) {
   }
private:
   int i_;
   int j_;
};

using namespace std;

int main() {
   vector<A> v;
   A a1(1,2);
   cout << "v.push_back(a1)" << endl;
   v.push_back(a1);                // echte Kopie (default-Kopierkonstruktor)
   cout << "v.emplace(v.end(), 3, 4)" << endl;
   v.emplace(v.end(), 3, 4);
}
