/* cppbuch/k24/array2d/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<showSequence.h>
#include"array2d.h"
using namespace std;

int main() {
   Array2d<int> arr(5, 7, 0);
   cout << "at():" << endl;
   for(int z=0; z < arr.getZeilen(); ++z) {
       for(int s=0; s < arr.getSpalten(); ++s) {
          arr.at(z, s) = 10*z+s;                    // at()
          cout << arr.at(z, s) << " ";
       }
       cout << endl;
   }
   cout << "[]():" << endl;
   for(int z=0; z < arr.getZeilen(); ++z) {
       for(int s=0; s < arr.getSpalten(); ++s) {
          arr[z][s] = 10*z+s;                      // operator[]
          cout << arr[z][s] << " ";
       }
       cout << endl;
   }

   Array2d<int> arr1(arr);  // Kopierkonstruktor
   showSequence(arr1);

   Array2d<int> arr2(Array2d<int>(3, 3));  // moving Kopierkonstruktor
   showSequence(arr2);

   arr1.init(3);
   arr = arr1; // Zuweisungsoperator
   showSequence(arr);

   arr =  Array2d<int>(1, 1, 1000);  // moving Zuweisungsoperator
   showSequence(arr);

   Array2d<double> arrd(3, 4, 99.013);
   showSequence(arrd);
 
   Array2d<string> arrs(2, 5, "hello");  // Array mit Strings
   showSequence(arrs);

   // Vergleiche
   Array2d<double> d1(3, 4, 50.0), d2(3, 4, 100.0);
   cout.setf(ios_base::boolalpha);
   cout << " d1 < d2 : " << (d1 < d2) << endl;
   cout << " d1 > d2 : " << (d1 > d2) << endl;
   cout << " d1 == d2 : " << (d1 == d2) << endl;
   cout << " d1 != d2 : " << (d1 != d2) << endl;

   cout << "Ausgabe mit printArray():\n";
   printArray(d1);
}
