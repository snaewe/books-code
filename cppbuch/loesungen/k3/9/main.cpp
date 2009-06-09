/* cppbuch/loesungen/k3/9/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include"gettype.t"
using namespace std;

int main() {
   int i;
   cout << getType(i) << endl;
   unsigned int ui;
   cout << getType(ui) << endl;
   float f;  // nicht in getType() berücksichtigt!
   cout << getType(f) << endl;
   double d;
   cout << getType(d) << endl;
   char c;
   cout << getType(c) << endl;
   bool b;
   cout << getType(b) << endl;
}
