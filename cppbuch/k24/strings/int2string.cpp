/* cppbuch/k24/strings/int2string.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<string>
#include<climits>
#include<cstdlib>
#define PRINT(X) std::cout << (#X) << " = " << (X) << std::endl

namespace {
   std::string i2string(int i) {
      std::string ergebnis;
      if(i == 0) {
         ergebnis = "0";
      }
      else {
         bool negativ = (i < 0);
         while(i != 0) {
            ergebnis.insert(ergebnis.begin(), abs(i % 10) + '0');
            i /= 10;
         }
         if(negativ) {
            ergebnis.insert(ergebnis.begin(), '-');
         }
      }
      return ergebnis;
   }
}


int main() {
   PRINT(i2string(1 << 31));  
   PRINT(i2string(INT_MIN));  
   PRINT(i2string(-33));
   PRINT(i2string(-1));
   PRINT(i2string(-0));
   PRINT(i2string(0));
   PRINT(i2string(1));
   PRINT(i2string(33));
   PRINT(i2string(unsigned(-1) >> 1));
   PRINT(i2string(INT_MAX));
}
