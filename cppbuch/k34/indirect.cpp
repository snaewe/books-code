/* cppbuch/k34/indirect.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include <iostream>
#include "valarray"
using namespace std;


template<class T>
void print(const valarray<T>& v) {
   for(size_t i = 0; i < v.size(); ++i) 
     cout << '\t' << v[i];
   cout << endl;
}

int main() {
   valarray<double> v(10);  
   for(size_t i = 0; i < v.size(); ++i) v[i]= 0.1*i;
   print(v);
   cout << "Indirektes Array i_arr anlegen:\n";
   valarray<size_t> i_arr(v.size());  
   for(size_t i = 0; i < i_arr.size(); ++i) 
     i_arr[i]= i_arr.size() - i -1;
   print(i_arr);
   cout << "operator[](i_arr):\n";
   cout << "va = v[i_arr] = "; 
   valarray<double> va = v[i_arr];  
   print(va);

   cout << "KÜRZERES indirektes Array i1_arr anlegen:\n";
   valarray<size_t> i1_arr(v.size()-4);  
   for(size_t i = 0; i < i1_arr.size(); ++i) 
     i1_arr[i]= i1_arr.size() - i +2;
   print(i1_arr);
   cout << "Subset = alle Elemente der Adressen in i1_arr:\n"
           "(Benutzung von []() const)\n";
   const valarray<double> cv = v;  
   const valarray<double>& v1 = cv[i1_arr];  
   print(v1);
   cout << "Subset-Elemente = 20 setzen mit: v[i1_arr] = 20:\n"
           "(Benutzung von non-const [] gefolgt von "
           "indirect_array::op=())\n";
   v[i1_arr] = 20;
   print(v);
   cout << "Subset-Elemente mit v[i1_arr] = vb setzen:\n"
           "(Benutzung von non-const [] gefolgt von "
            "indirect_array::op=())" << endl
           << "vb =";
   valarray<double> vb(10);  
   for(size_t i = 0; i < vb.size(); ++i) vb[i]= 0.01*i;
   print(vb);

   v[i1_arr] = vb;
   print(v);
   cout << "Multiplikation: v[i1_arr] *= vb\n";
   v[i1_arr] *= vb;
   print(v);

}
