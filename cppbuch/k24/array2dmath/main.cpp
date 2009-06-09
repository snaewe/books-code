/* cppbuch/k24/array2dmath/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#if  __GNUC__*10+__GNUC_MINOR__ < 44
#error "Die Compilation dieses Programms setzt mindestens GNU C++ 4.4 voraus!"
#else

#include<iostream>
#define TESTARRAY2D
#include"array2d.h"
#include<cassert>
#include<numeric>
using namespace std;

int main() {
   Array2d<int> a1(2, 3, 1);
   Array2d<int> a2(2, 3, 2);
   Array2d<int> a3(2, 3, 3);
   Array2d<int> a4(3, 3, 4);
   Array2d<int> ergAdd(2, 3);
   // 2 Op
   cout << "a1+a2:" << endl;   a1.print();  cout << "+" << endl;  a2.print();  
   cout << "=" << endl;
   ergAdd = a1 + a2;
   ergAdd.print();
   assert(ergAdd == a3);
   // 3 op
   cout << "-a1 + 2*a2 + a3:" << endl << "-" << endl;   
   a1.print();  cout << "+ 2*" << endl;  a2.print();  
   cout << "+" << endl;  a3.print();    cout << "=" << endl;
   ergAdd = -a1 + 2*a2 + a3;  
   ergAdd.print();
   assert(ergAdd == Array2d<int>(2, 3, 6));
   // 4 op
   cout << "a1+a2-a3 +a1:" << endl;   a1.print();  cout << "+" << endl;  a2.print();  
   cout << "-" << endl;  a3.print();  cout << "+" << endl;  a1.print();     
cout << "=" << endl;
   ergAdd = a1 + a2 - a3 + a1;
   ergAdd.print();
 
    //mult 
   Array2d<int> ergMult(2, 4);
   cout << "\nb1*b2:" << endl;
   Array2d<int> b1(2, 3);
   iota(b1.begin(), b1.end(), 1);
   b1.print();
   cout << "*" << endl;
   Array2d<int> b2(3, 4);
   iota(b2.begin(), b2.end(), -4);
   b2.print();
   cout << "=" << endl;
   ergMult = b1 * b2;
   ergMult.print();
   int x[] = {8, 14, 20, 26, 8, 23, 38, 53};
   assert(ergMult == Array2d<int>(2, 4, x));
 
   Array2d<int> c0(3, 3);
   iota(c0.begin(), c0.end(), 1);
   Array2d<int> c1(3, 3, 1);
   Array2d<int> ergc(3, 3, 1);
   Array2d<int> e(3, 3, 0);
   for(size_t i = 0; i < e.getZeilen(); ++i) {
      e[i][i] = 1; // Einheitsmatrix
   }
   cout << "\nc0 *= c1:" << endl;
   c0.print(); cout << " *= " << endl; c1.print(); cout << " = \n";
   c0 *= c1;
   c0.print();
   cout << "\nergc = c0 * e:" << endl;
   ergc = c0 * e;
   ergc.print();
   cout << "\nc0 = 2*c0:" << endl;
   c0 = 2*c0 ;
   c0.print();
   cout << "\nergc = c0 * e + e*2:" << endl;
   ergc = c0 * e + e*2;
   ergc.print();
}
#endif
