/* cppbuch/k5/array2d/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"array2d.h"
#include<iostream>
using namespace std;

int main() {
   Array2d<int> arr(5, 7);
   arr.init(0);

   for(int z=0; z < arr.getZeilen(); ++z) {
       for(int s=0; s < arr.getSpalten(); ++s) {
          //arr.at(z, s) = 10*z+s;
          //cout << arr.at(z, s) << " ";
          arr[z][s] = 10*z+s;
          cout << arr[z][s] << " ";
       }
       cout << endl;
   }
   cout << "[]():" << endl;
   printArray(arr);

   Array2d<int> arr1(arr);  // Kopierkonstruktor
   printArray(arr1);

   arr1.init(3);
   arr = arr1; // Zuweisungsoperator
   printArray(arr);

   Array2d<double> arrd(3, 4, 99.013);
   printArray(arrd);

   Array2d<string> arrs(2, 5, "hello");
   printArray(arrs);

}
