/* cppbuch/k1/floatlimits.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include <iostream>
#include<limits>           // hier sind die Bereichsinformationen
using namespace std;

int main() {
   cout << "Grenzwerte für Float-Zahl-Typen:" << endl;
   cout  << "Float-Min: " << numeric_limits<float>::min() << endl;
   cout  << "Float-Max: " << numeric_limits<float>::max() << endl;
   cout  << "Double-Min: " << numeric_limits<double>::min() << endl;
   cout  << "Double-Max: " << numeric_limits<double>::max() << endl;
   cout  << "Long-Double-Min: " << numeric_limits<long double>::min() << endl;
   cout  << "Long-Double-Max: " << numeric_limits<long double>::max() << endl;
   cout << "Anzahl der Bytes für:" << endl;
   cout << "float         " << sizeof(float) << endl;
   cout << "double        " << sizeof(double) << endl;
   cout << "long double   " << sizeof(long double) << endl;
}
