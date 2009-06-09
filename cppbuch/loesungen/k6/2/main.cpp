/* cppbuch/loesungen/k6/2/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"format.h"
#include<iostream>
using namespace std;

int main() {

   Format f(12, 3);
   cout << "-123456789.906625 :" 
        << f.toString(-123456789.906625) << endl;
   cout << "-0,00123456789    :" 
        << f.toString(-0.00123456789) << endl;
   cout << "0,00              :" 
        << f.toString(0.00) << endl;
   cout << "-12345.6789906625 :" 
        << f.toString(-12345.6789906625) << endl;
   cout << "1.00000           :" 
        << f.toString(1.0) << endl;

   Format fi(12, 0);

   cout << "123               :" 
        << fi.toString(123) << endl;
   cout << "-123456789.906625 :" 
        << fi.toString(-123456789.906625) << endl;
}
