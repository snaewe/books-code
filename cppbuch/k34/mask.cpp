/* cppbuch/k34/mask.cpp
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
   valarray<double> v(12);  
   for(size_t i = 0; i < v.size(); ++i) v[i] = i;

   cout << "operator[](const valarray<bool>&):\n";
   cout << "v= "; 
   print(v);
   valarray<bool> maske(10); // muss  <= v.size() sein
   // jeden dritten = true setzen
   for(size_t i = 0; i < maske.size(); i+=3) maske[i] = true;
   cout << "maske= ";print(maske);

   cout << "Untermenge = alle Elemente aus v mit maske == true:\n"
           "(Benutzung von []() const)\n";
   const valarray<double> cv = v;  
   const valarray<double>& v1 = cv[maske];  
   print(v1);
   cout << "Elemente der Untermenge = 20 setzen mit  v[maske] = 20:\n"
           "(Benutzung von non-const [] gefolgt von mask_array::op=())\n";
   v[maske] = 20;
   print(v);
   cout << "Elemente der Untermenge mit v[maske]= valarray vb setzen:\n"
           "(Benutzung von non-const [] gefolgt von mask_array::op=())\nvb =";
   valarray<double> vb(10), vx(v);
   // vb.size() >= Anzahl der true-Elemente in Maske maske  
   for(size_t i = 0; i < vb.size(); ++i) 
      vb[i] = 0.1 * i;
   print(vb);
   v[maske] = vb;
   print(v);
   cout << "multipliziere: v[b] *= vb\n";
   v[maske] *= vb;
   print(v);
   cout << "multipliziere: vx[b] *= vb\n";
   vx[maske] *= vb;
   print(vx);
}
