/* cppbuch/k24/folgen/accumulate.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<vector>
#include<numeric>
#include<iostream>
#include<string>
#if  __GNUC__*10+__GNUC_MINOR__ < 44 
#include<ersatziota.h>
#endif
using namespace std;

int main() {
    vector<int> v(10);
    iota(v.begin(), v.end(), 1);
    cout << "Summe = "     
         << accumulate(v.begin(), v.end(), 0)    // 55
         << endl;

    cout << "Produkt = "  
         << accumulate(v.begin(), v.end(), 1L,
                       multiplies<long>())            // 3628800
         << endl;

    // accumulate mit string
    vector<string> vstr(26);
    iota(vstr.begin(), vstr.end(), 'A'); // Vektor mit Buchstaben füllen
    cout << accumulate(vstr.begin(), vstr.end(), string("Alphabet: "))
         << endl; 
}
