/* cppbuch/loesungen/k1/2.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
using namespace std;

int main() {
   unsigned int ui = 0;
   unsigned long int uli = 0;
   cout << "max. unsigned int     = "<< ~ui       << endl;
   cout << "max. unsigned long int= "<< ~uli      << endl;
   cout << "max. int              = "<< (~ui>>1)  << endl;
   cout << "max. long int         = "<< (~uli>>1) << endl;
}
