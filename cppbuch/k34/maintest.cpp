/* cppbuch/k34/maintest.cpp
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

   cout << endl << "KÜRZERES indirektes Array i1_arr anlegen:\n";
   valarray<size_t> i_arr(v.size()-4);  
   for(size_t i = 0; i < i_arr.size(); ++i) 
     i_arr[i]= i_arr.size() - i +2;
   print(i_arr);

   cout << endl
        << "Subset = alle Elemente der Adressen in i1_arr:\n"
           "(Benutzung von []() const)\n";

   const valarray<double> u = v[i_arr];  
   print(u);
   cout << endl;

   for(size_t i = 0; i < i_arr.size(); ++i) {
      cout << u[i_arr[i]] << "  " << v[i] 
           << "  !  " <<  v[i_arr[i]] << "  " << u[i] ;
   cout << endl;
   }



 
}
